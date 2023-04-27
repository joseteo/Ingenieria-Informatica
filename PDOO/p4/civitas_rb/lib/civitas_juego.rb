require_relative 'tablero'
require_relative 'sorpresa'
require_relative 'jugador'
require_relative 'casilla'
require_relative 'dado'
require_relative 'titulo_propiedad'
require_relative 'gestor_estados'
require_relative 'estados_juego'
require_relative 'casilla_calle'
require_relative 'casilla_juez'
require_relative 'casilla_sorpresa'
require_relative 'casilla_impuesto'
require_relative 'sorpresa_ircarcel'
require_relative 'sorpresa_iracasilla'
require_relative 'sorpresa_salircarcel'
require_relative 'sorpresa_pagarcobrar'
require_relative 'sorpresa_porcasahotel'
require_relative 'sorpresa_porjugador'
require_relative 'sorpresa_especulador'

module Civitas

class Civitas_juego
  
  attr_accessor :indiceJugadoractual
  attr_accessor :mazo
  attr_accessor :estado
  attr_accessor :jugadores
  attr_accessor :gestor
  attr_accessor :tablero
  
  
  def avanzajugador
    jugadoractual = getjugadoractual()
    posicionactual = jugadoractual.numCasillaActual
    tirada = Dado.instance.tirar
    posicionnueva = @tablero.nueva_posicion(posicionactual, tirada)
    casilla = Casilla
    casilla = @tablero.get_casilla(posicionnueva)
    contabilizar_pasos_por_salida(jugadoractual)
    jugadoractual.mover_a_casilla(posicionnueva)
    casilla.recibejugador(@indiceJugadoractual, @jugadores)
    contabilizar_pasos_por_salida(jugadoractual)
  end
  
    def cancelar_hipoteca(ip)
    resultado = @jugadores.at(@indiceJugadoractual).cancelar_hipoteca(ip)
    return resultado
  end
  
  def initialize(nombres)
    @jugadores= Array.new
    for i in 0...nombres.length()
      @jugadores.push(Jugador.new(nombres.at(i)))
    end
    
    @gestor= Gestorestados.new
    @estado= @gestor.estado_inicial()
    
    @indiceJugadoractual= Dado.instance.quien_empieza(@jugadores.length)
    
    @mazo= Mazo_sorpresas.new
    
    inicializar_tablero(@mazo)
    
    inicializar_mazosorpresas(@tablero)
  end
  
  def comprar 

    res=false
    jugadoractual = getjugadoractual()
    numcasillaactual = jugadoractual.numCasillaActual
    casilla = @tablero.get_casilla(numcasillaactual)
    titulo = casilla.titulopropiedad

    res = jugadoractual.comprar(titulo)
   
    return res
  end
  
  def construir_casa(ip)
    return @jugadores.at(@indiceJugadoractual).construircasa(ip)
  end
  
  def construir_hotel(ip)
    return @jugadores.at(@indiceJugadoractual).construirhotel(ip)
  end
  
  def contabilizar_pasos_por_salida(jugadoractual)
    if (@tablero.get_por_salida() > 0)
      jugadoractual.pasa_por_salida()
    end
  end
  
  def final_del_juego()
   banca_rota=false
   for i in 0...@jugadores.length()
    banca_rota = true if (@jugadores.at(i).enbancarrota() == true)
   end
   return banca_rota
  end
  
  def getcasillaactual
    return @tablero.get_casilla(@jugadores.at(@indiceJugadoractual).numCasillaActual)
  end
  
  def getjugadoractual
    return @jugadores.at(@indiceJugadoractual)
  end
  
  def hipotecar(ip)
    return @jugadores.at(@indiceJugadoractual).hipotecar(ip)
  end
  
  def inicializar_mazosorpresas(tablero)
    @mazo.al_mazo(Sorpresa_ircarcel.new(tablero))
    @mazo.al_mazo(Sorpresa_iracasilla.new(tablero, 18, "Debes ir a la casilla 18"))
    @mazo.al_mazo(Sorpresa_iracasilla.new(tablero, 2, "Debes ir a la casilla 2"))
    @mazo.al_mazo(Sorpresa_salircarcel.new(@mazo))
    @mazo.al_mazo(Sorpresa_pagarcobrar.new(200, "Has ganado el concurso de belleza, ganas 200 euros"))
    @mazo.al_mazo(Sorpresa_pagarcobrar.new(-100, "Exceso de velocidad, pagas 100 euros de multa"))
    @mazo.al_mazo(Sorpresa_porcasahotel.new(100, "Ganas 100 euros por cada casa u hotel"))
    @mazo.al_mazo(Sorpresa_porcasahotel.new(-50, "Pagas 50 euros por cada casa u hotel"))
    @mazo.al_mazo(Sorpresa_porjugador.new(100, "Cada jugador te dona 100 euros"))
    @mazo.al_mazo(Sorpresa_porjugador.new(-50, "Debes pagar 50 euros a cada jugador"))
    @mazo.al_mazo(Sorpresa_especulador.new(300))
  end
  
  def inicializar_tablero(mazo)
    @tablero = Tablero.new(5)
    #casilla 0 es la salida
    @tablero.aniade_casilla( Casilla_calle.new(Titulo_propiedad.new("Calle 1", 50, 10, 150, 500, 250)))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 2", 52, 10, 200, 525, 275)))
    @tablero.aniade_casilla(Casilla_sorpresa.new(mazo, "Sorpresa"))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 4", 55, 11, 300, 550, 300)))
    #casilla 5 es la de carcel
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 6", 60, 12, 400, 600, 350)))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 7", 65, 13, 450, 650, 400)))
    @tablero.aniade_casilla(Casilla_sorpresa.new(mazo, "Sorpresa"))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 9", 70, 14, 500, 700, 450)))
    @tablero.aniade_casilla(Casilla.new("Parking"))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 11", 75, 15, 600, 750, 500)))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 12", 80, 16, 650, 800, 550)))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 13", 85, 17, 700, 850, 600)))
    @tablero.aniade_casilla(Casilla_sorpresa.new(mazo, "Sorpresa"))
    @tablero.aniade_casilla(Casilla_juez.new(@tablero.numCasillaCarcel, "Juez"))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 16", 90, 18, 800, 900, 650)))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 17", 95, 19, 900, 950, 700)))
    @tablero.aniade_casilla(Casilla_impuesto.new(200, "Impuesto"))
    @tablero.aniade_casilla(Casilla_calle.new(Titulo_propiedad.new("Calle 19", 100, 20, 1000, 750, 1000)))
  end
    
  def pasar_turno()
    @indiceJugadoractual =  (@indiceJugadoractual +1)%@jugadores.length()
  end
  
  def ranking()
    aux = @jugadores
    aux = aux.sort { |x,y| x <=> y }
    return aux
  end
    
  def salir_carcel_pagando()
    resultado= @jugadores.at(@indiceJugadoractual).salir_carcel_pagando()
    return resultado
  end
  
  def salir_carcel_tirando()
    return @jugadores.at(@indiceJugadoractual).salir_carcel_Tirando()
  end
    
  def siguientepaso
    jugadoractual = getjugadoractual()
    operacion = @gestor.operaciones_permitidas(jugadoractual, @estado)
    if operacion == Operacionesjuego::PASAR_TURNO
      pasar_turno()
      siguiente_paso_completado(operacion)
    elsif operacion == Operacionesjuego::AVANZAR
      avanzajugador()
      siguiente_paso_completado(operacion)
    end
    return operacion
  end
  
  def siguiente_paso_completado(operacion)
    jugador_actual=@jugadores.at(@indiceJugadoractual)
    @estado=@gestor.siguiente_estado(jugador_actual, @estado, operacion)
  end
  
  def vender(ip)
    return @jugadores.at(@indiceJugadoractual).vender(ip)
  end
  
  private :avanzajugador
  
end

end