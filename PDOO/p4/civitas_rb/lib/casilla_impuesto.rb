module Civitas

class Casilla_impuesto < Casilla
  
  def initialize(cantidad, nombre)
    super(nombre)
    @importe=cantidad
  end
  
  def recibejugador(iactual, todos)
    if(jugador_correcto(iactual, todos))
      informe(iactual, todos)
      todos.at(iactual).paga_impuesto(@importe)
    end
  end
  
  def to_string()
    return "#{super}, { importe= #{@importe} }"
  end
  
end
end