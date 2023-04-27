require_relative 'tablero'
require_relative 'mazo_sorpresas'
require_relative 'diario'

module Civitas

class Sorpresa
  
  def initialize(texto)
    @texto=texto
  end
  
  def aplicar_a_jugador(actual, todos) end
  
  def informe(actual, todos)
    Diario.instance.ocurre_evento("se esta aplicando una sorpresa al jugador #{todos.at(actual).nombre}
    , \nLa informacion de laq sorpresa es #{to_string}")
  end
  
  def jugador_correcto(actual, todos)
    resultado=false
    if actual >=0 and actual < todos.length
      resultado=true
    end
    return resultado
  end
  
  def to_string
    return "Sorpresa{ texto=#{@texto}, valor=#{@valor.to_s}, tipo=#{@tipo} }"
  end
  
  attr_reader :texto
  
end
end
