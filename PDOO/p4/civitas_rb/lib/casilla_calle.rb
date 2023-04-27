module Civitas

class Casilla_calle < Casilla

  def initialize(titulo)
    super(titulo.nombre)
    @importe = titulo.preciocompra
    @titulopropiedad = titulo
    @nombre = super.nombre
  end
  
  def recibejugador(iactual, todos)
    if(jugador_correcto(iactual, todos)==true)
      
      informe(iactual, todos)
      if(!@titulopropiedad.tienepropietario)
        
        todos.at(iactual).puede_comprar_casilla
        todos.at(iactual).puedeComprar = true
      else
        
        @titulopropiedad.tramitaralquiler(todos.at(iactual))
        todos.at(iactual).puedeComprar=false
      end
    end
  end
  
  def to_string()
    return "#{super}, { importe= #{@importe} }"
  end
  
  attr_reader :titulopropiedad
    
end
end