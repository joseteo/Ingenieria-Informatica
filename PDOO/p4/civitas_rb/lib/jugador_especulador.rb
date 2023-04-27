module Civitas

class Jugador_especulador < Jugador
  @@factorespeculador=2
  
  def initialize(jugador, fianza)
    super(jugador)
    @fianza=fianza
    @especulador=true
    for i in 0...super.propiedades.length
      super.propiedades.at(i).actualizar_propietario_por_conversion(self)
    end
  end
  
  def encarcelar(numCasillaCarcel)
    resultado = false
    if !super.encarcelado
      if !super.tiene_salvoconducto
        if @fianza >= super.saldo
          resultado=true
        else
          super.paga(@fianza)
          Diario.instance.ocurre_evento("El jugador #{super.nombre} se ha librado de la carcel pagando una fianza")
        end
      else
        resultado=false
        super.perder_salvoconducto
        Diario.instance.ocurre_evento("El jugador #{super.nombre} se libra de la carcel")
      end
    end
    return resultado
  end
  
  def gethotelesmax
    return (super.hotelesMax * @@factorespeculador)
  end
  
  def getcasasmax
    return (super.casasMax * @@factorespeculador)
  end
  
  def paga_impuesto(cantidad)
    resultado=false
    if !super.encarcelado
      impuesto = cantidad / 2
      Diario.instance.ocurre_evento("El jugador #{super.nombre} paga #{impuesto} euros por impuesto")
    end
    return resultado
  end
  
  def to_string
    return "Jugador{ nombre= #{super.nombre}, encarcelado= #{super.is_encarcelado.to_s}, numCasillaActual= #{super.numCasillaActual}, puedeComprar= #{super.puedeComprar}, 
            saldo= #{super.saldo}, especulador= #{@especulador.to_s} }"
  end
  
  
end
end