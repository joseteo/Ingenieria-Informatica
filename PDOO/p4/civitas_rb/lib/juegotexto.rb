require_relative 'vistatextual'
require_relative 'civitas_juego'
require_relative 'controlador'
require_relative 'dado'

module Civitas
  
class Juegotexto
  def self.main
    vista = Vistatextual.new
    
    nombres = Array.new
    for i in 1..4
      nombres.push("Jugador#{i}")
    end
    
    juego = Civitas_juego.new(nombres)
    
    Dado.instance.setdebug(true)
    
    controlador = Controlador.new(juego, vista)
    
    controlador.juega()
  end
end

Juegotexto.main


end