module Civitas
  
class Sorpresa_porjugador < Sorpresa
  
  def initialize(valor, texto)
    super(texto)
    @valor=valor
  end
  
  
  def aplicar_a_jugador(actual, todos)
    if (jugador_correcto(actual, todos))
      informe(actual, todos)
      s1 = Sorpresa_pagarcobrar.new(@valor * -1, "PAGARCOBRAR")
      for i in 0...actual
        s1.aplicar_a_jugador(i, todos)
      end
      for j in actual+1...todos.length
        s1.aplicar_a_jugador(j, todos)
      end
      s2 = Sorpresa_pagarcobrar.new(@valor * (todos.length - 1), "PAGARCOBRAR0")
      s2.aplicar_a_jugador(actual, todos)
    end
  end
  
  def to_string()
    return super
  end
  
end
end