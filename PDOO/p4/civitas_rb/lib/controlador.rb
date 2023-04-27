require_relative 'operaciones_juego'
require_relative 'civitas_juego'
require_relative 'vistatextual'
require_relative 'operaciones_inmobiliarias'
require_relative 'respuestas'
require_relative 'gestiones_inmobiliarias'
require_relative 'salidas_carcel'

module Civitas
class Controlador
  
  def initialize(jueg, vist)
    @juego=jueg
    @vista=vist
  end
  
  def juega
    @vista.set_civitas_juego(@juego)
    while (!@juego.final_del_juego)
      @vista.actualizar_vista()
      
      @vista.pausa
      
      operacionsig= @juego.siguientepaso
      @vista.mostrar_siguiente_operacion(operacionsig)
      
      
      if operacionsig != Operacionesjuego::PASAR_TURNO
        @vista.mostrar_eventos()
      end
      
      puts @juego.final_del_juego()

      if !@juego.final_del_juego()
        
        
        if operacionsig!=nil
        case operacionsig
        
        when Operacionesjuego::COMPRAR
          resp = @vista.comprar
          if resp == Respuestas::SI
            @juego.comprar
          end
          @juego.siguiente_paso_completado(operacionsig)
          
        when Operacionesjuego::GESTIONAR
          @vista.gestionar
          gest = @vista.getgestion
          gest = gest.to_s
          
          if gest.chomp.eql? '0'
            gest = Gestiones_inmobiliarias::VENDER
          elsif gest.chomp.eql? '1'
            gest = Gestiones_inmobiliarias::HIPOTECAR
          elsif gest.chomp.eql? '2'
            gest = Gestiones_inmobiliarias::CANCELAR_HIPOTECA
          elsif gest.chomp.eql? '3'
            gest = Gestiones_inmobiliarias::CONSTRUIR_CASA
          elsif gest.chomp.eql? '4'
            gest = Gestiones_inmobiliarias::CONSTRUIR_HOTEL
          elsif gest.chomp.eql? '5'
            gest = Gestiones_inmobiliarias::TERMINAR
          end

          ip = @vista.getpropiedad
          op = Operaciones_inmobiliarias.new(gest, ip)
          
          
          case (op.gestion)
          
          when Gestiones_inmobiliarias::VENDER
            @juego.vender(@vista.getpropiedad)
            
          when Gestiones_inmobiliarias::HIPOTECAR
            @juego.hipotecar(@vista.getpropiedad)
            
          when Gestiones_inmobiliarias::CANCELAR_HIPOTECA
            @juego.cancelar_hipoteca(@vista.getpropiedad)
            
          when Gestiones_inmobiliarias::CONSTRUIR_CASA
            @juego.construir_casa(@vista.getpropiedad)
            
          when Gestiones_inmobiliarias::CONSTRUIR_HOTEL
            @juego.construir_hotel(@vista.getpropiedad)
            
          else Gestiones_inmobiliarias::TERMINAR
            @juego.siguiente_paso_completado(operacionsig)
            
          end
          
        when Operacionesjuego::SALIR_CARCEL
          sal = @vista.salir_carcel
          if sal == Salidas_carcel::PAGANDO
            @juego.salir_carcel_pagando
          elsif sal == Salidas_carcel::TIRANDO
            @juego.salir_carcel_tirando
          end
          @juego.siguiente_paso_completado(operacionsig)
        end
        end
      end
    end
    rank = @juego.ranking
    puts "RANKING"
    for i in 0...rank.length
      puts (i+1)
      puts rank[i].to_string
    end
 
  end
  
  
end
end