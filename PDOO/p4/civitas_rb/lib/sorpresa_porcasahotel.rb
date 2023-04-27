module Civitas
  
class Sorpresa_porcasahotel < Sorpresa
  
  def initialize(valor, texto)
    super(texto)
    @valor=valor
  end
  
  
  def aplicar_a_jugador(actual, todos)
    if (jugador_correcto(actual, todos))
      informe(actual, todos)
      todos.at(actual).modificar_saldo(@valor * todos.at(actual).cantidadcasashoteles)
    end
  end
  
  def to_string()
    return super
  end
  
end
end