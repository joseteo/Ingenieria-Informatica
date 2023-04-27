module Civitas
  
class Sorpresa_pagarcobrar < Sorpresa
  
  def initialize(valor, texto)
    super(texto)
    @valor=valor
  end
  
  
  def aplicar_a_jugador(actual, todos)
    if (jugador_correcto(actual, todos))
      informe(actual, todos)
      todos.at(actual).modificar_saldo(@valor)
    end
  end
  
  def to_string()
    return super
  end
  
end
end