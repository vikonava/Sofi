#!/usr/bin/env ruby

#####################
#       Clases      #
#####################
class Cuadruplo
    attr_reader :opId, :oper1, :oper2, :result
    attr_writer :opId, :oper1, :oper2, :result
    
    def initialize(cuadText)
        cuadText = cuadText.split(',')
        @opId = cuadText[0].to_i
        @oper1 = cuadText[1].to_i
        @oper2 = cuadText[2].to_i
        @result = cuadText[3].to_i
    end
end

class Procs
    attr_reader :name, :returnType, :params, :initCuad, :retAddress

    def initialize(cuadText)
        cuadText = cuadText.split(',');
        @name = cuadText[0].to_s
        @returnType = cuadText[1].to_s
        @params = cuadText[2].to_i
        @initCuad = cuadText[3].to_i
        @retAddress = cuadText[4].to_i
    end
end

#####################################
#       Inicializa Variables        #
#####################################
@cuadruplos = Hash.new
@virtualMemory = Hash.new
@dirprocs = Array.new
@stackProcs = Array.new
@stackPointer = Array.new
@stackReturn = Array.new
@apuntador = 1; # El index de los cuadruplos inicia en el 1

#####################################
#       Define Limites Memoria      #
#####################################
VAR_SPACE = 1000

GLOBAL_CHAR = 0
GLOBAL_TEXT = 1000
GLOBAL_NUMBER = 2000
GLOBAL_DECIMAL = 3000
GLOBAL_BOOL = 4000
LOCAL_CHAR = 5000
LOCAL_TEXT = 6000
LOCAL_NUMBER = 7000
LOCAL_DECIMAL = 8000
LOCAL_BOOL = 9000
TEMP_CHAR = 10000
TEMP_TEXT = 11000
TEMP_NUMBER = 12000
TEMP_DECIMAL = 13000
TEMP_BOOL = 14000
CONST_CHAR = 15000
CONST_TEXT = 16000
CONST_NUMBER = 17000
CONST_DECIMAL = 18000
CONST_BOOL = 19000

#########################
#       Funciones       #
#########################

# Carga archivo de los cuadruplos en el hash
def loadCuadruplos
    part = 0
    counter = 1
    file = File.new(ARGV[0], "r")
    while (line = file.gets)
        if line.strip == "#"
            part += 1
        else
            case part
            when 0
                temp = line.strip.split(",")
                virtualAddress = temp[0].to_i
                @virtualMemory[virtualAddress] = temp[1].gsub(/\r\n?/,"").gsub(/"/, "");
                # En caso de que haya comas en el string
                for i in 2..temp.length-1
                    @virtualMemory[virtualAddress] += "," + temp[i].gsub(/\r\n?/,"").gsub(/"/, "");
                end
                # En caso de que sea numero o flotante
                @virtualMemory[virtualAddress] = temp[1].to_i if (virtualAddress >= GLOBAL_NUMBER && virtualAddress <= GLOBAL_NUMBER+VAR_SPACE-1) || (virtualAddress >= LOCAL_NUMBER && virtualAddress <= LOCAL_NUMBER+VAR_SPACE-1) || (virtualAddress >= TEMP_NUMBER && virtualAddress <= TEMP_NUMBER+VAR_SPACE-1) || (virtualAddress >= CONST_NUMBER && virtualAddress <= CONST_NUMBER+VAR_SPACE-1)
                @virtualMemory[virtualAddress] = temp[1].to_f if (virtualAddress >= GLOBAL_DECIMAL && virtualAddress <= GLOBAL_DECIMAL+VAR_SPACE-1) || (virtualAddress >= LOCAL_DECIMAL && virtualAddress <= LOCAL_DECIMAL+VAR_SPACE-1) || (virtualAddress >= TEMP_DECIMAL && virtualAddress <= TEMP_DECIMAL+VAR_SPACE-1) || (virtualAddress >= CONST_DECIMAL && virtualAddress <= CONST_DECIMAL+VAR_SPACE-1)
            when 1
                @cuadruplos[counter] = Cuadruplo.new(line.strip)
                counter += 1
            when 2
                @dirprocs += [Procs.new(line.strip)]
            end
        end
    end
    file.close
end


#####################
#       Main        #
#####################
if !ARGV.empty? # Si pasa el parametro del archivo a cargar
    loadCuadruplos # carga el archivo de OBJ
    
    while @apuntador <= @cuadruplos.length do
        #obten cuadruplo actual
        cuadruplo = @cuadruplos[@apuntador]
        # Realizar Operacion del Apuntador
        case cuadruplo.opId
            when 10 # Suma
                @virtualMemory[cuadruplo.result] = @virtualMemory[cuadruplo.oper1] + @virtualMemory[cuadruplo.oper2]
            when 20 # Resta
                @virtualMemory[cuadruplo.result] = @virtualMemory[cuadruplo.oper1] - @virtualMemory[cuadruplo.oper2]
            when 30 # Multiplicacion
                @virtualMemory[cuadruplo.result] = @virtualMemory[cuadruplo.oper1] * @virtualMemory[cuadruplo.oper2]
            when 40 # Division
                @virtualMemory[cuadruplo.result] = @virtualMemory[cuadruplo.oper1] / @virtualMemory[cuadruplo.oper2]
            when 50 # Modulo
                @virtualMemory[cuadruplo.result] = @virtualMemory[cuadruplo.oper1] % @virtualMemory[cuadruplo.oper2]
            when 60 # Y
                @virtualMemory[cuadruplo.result] = (@virtualMemory[cuadruplo.oper1] && @virtualMemory[cuadruplo.oper2] ? true : false)
            when 70 # O
                @virtualMemory[cuadruplo.result] = (@virtualMemory[cuadruplo.oper1] || @virtualMemory[cuadruplo.oper2] ? true : false)
            when 80 # Mayor Que
                @virtualMemory[cuadruplo.result] = (@virtualMemory[cuadruplo.oper1] > @virtualMemory[cuadruplo.oper2] ? true : false)
            when 90 # Menor Que
                @virtualMemory[cuadruplo.result] = (@virtualMemory[cuadruplo.oper1] < @virtualMemory[cuadruplo.oper2] ? true : false)
            when 100 # Diferente Que
                @virtualMemory[cuadruplo.result] = (@virtualMemory[cuadruplo.oper1] != @virtualMemory[cuadruplo.oper2] ? true : false)
            when 110 # Igual Que
                @virtualMemory[cuadruplo.result] = (@virtualMemory[cuadruplo.oper1] == @virtualMemory[cuadruplo.oper2] ? true : false)
            when 120 # Igualar Variable
                @virtualMemory[cuadruplo.result] = @virtualMemory[cuadruplo.oper1];
            when 130 # Goto
                @apuntador = cuadruplo.result-1
            when 140 # Goto False
                @apuntador = cuadruplo.result-1 if !@virtualMemory[cuadruplo.oper1]
            when 150 # Goto True
                @apuntador = cuadruplo.result-1 if @virtualMemory[cuadruplo.oper1]
            when 160 # GoSub
                @stackPointer.push(@apuntador)
                @apuntador = @dirprocs[cuadruplo.oper1].initCuad
                @stackReturn.push(@dirprocs[cuadruplo.oper1].retAddress)
            when 170 # ERA
                # Crear Buffer de memoria y salvar los datos al stack de procs
                memory_buffer = Hash.new
                @virtualMemory.each { |key, value|
                    if (key >= 5000 && key < 15000)
                        memory_buffer[key] = value
                        @virtualMemory.delete(key)
                    end
                }
                @stackProcs.push(memory_buffer)
            when 180 # RET From Function
                # Devolver apuntador
                @apuntador = @stackPointer.pop()
                # Destruir Memoria local de funcion
                @virtualMemory.each { |key, value| @virtualMemory.delete(key) if key >= 5000 && key < 15000 }
                # Recupera memoria local del stack
                @virtualMemory.merge!(@stackProcs.pop())
            when 190 # Print
                print @virtualMemory[cuadruplo.result].to_s
                STDOUT.flush
            when 200 # Read
                @virtualMemory[cuadruplo.result] = STDIN.gets.strip
                if (cuadruplo.result >= GLOBAL_NUMBER && cuadruplo.result <= GLOBAL_NUMBER+VAR_SPACE-1) || (cuadruplo.result >= LOCAL_NUMBER && cuadruplo.result <= LOCAL_NUMBER+VAR_SPACE-1) || (cuadruplo.result >= TEMP_NUMBER && cuadruplo.result <= TEMP_NUMBER+VAR_SPACE-1)
                    @virtualMemory[cuadruplo.result] = Integer(@virtualMemory[cuadruplo.result])
                end
                if (cuadruplo.result >= GLOBAL_DECIMAL && cuadruplo.result <= GLOBAL_DECIMAL+VAR_SPACE-1) || (cuadruplo.result >= LOCAL_DECIMAL && cuadruplo.result <= LOCAL_DECIMAL+VAR_SPACE-1) || (cuadruplo.result >= TEMP_DECIMAL && cuadruplo.result <= TEMP_DECIMAL+VAR_SPACE-1)
                    @virtualMemory[cuadruplo.result] = Float(@virtualMemory[cuadruplo.result])
                end
            when 210 # Print New Line
                puts ""
            when 220 # Program Quit
                @apuntador = @cuadruplos.length;
            when 230 # Crea Param de una Funcion
                funcmem = ((cuadruplo.oper1/VAR_SPACE)%5)*VAR_SPACE+LOCAL_CHAR
                i = 0;
                while @virtualMemory.has_key?(funcmem+i)
                    i += 1
                end
                @virtualMemory[funcmem+i] = @virtualMemory[cuadruplo.oper1] if cuadruplo.oper1 < 5000 || cuadruplo.oper1 >= 15000
                @virtualMemory[funcmem+i] = @stackProcs.last[cuadruplo.oper1]  if cuadruplo.oper1 >= 5000 && cuadruplo.oper1 < 15000
            when 240 # RETURN
                @virtualMemory[@stackReturn.pop()] = @virtualMemory[cuadruplo.oper1]
            else
                puts "UNRecog: "+cuadruplo.opId.to_s
        end
        
        @apuntador += 1; # Incrementa apuntador
    end

    #puts "\nMemoria Virtual Final:\n"+@virtualMemory.to_s
else
    puts "Debes poner el argumento del codigo objeto a ejecutar."
end