module Civitas

require_relative 'jugador_especulador'

class Sorpresa_especulador < Sorpresa

  def initialize(valor)
    super("Debes converitrte en especulador")
    @valor=valor
  end


  def aplicar_a_jugador(actual, todos)
    if (jugador_correcto(actual, todos))
      informe(actual, todos)
      especulador = Jugador_especulador.new(todos.at(actual), @valor)
      todos.fill(especulador, actual, 1)
    end
  end

end
end
