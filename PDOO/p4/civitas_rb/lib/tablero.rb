require_relative 'casilla'


module Civitas

class Tablero
  def initialize (indiceCarcel)
    if indiceCarcel>=1
      @numCasillaCarcel=indiceCarcel
    else
      @numCasillaCarcel=1
    end
    
    @casillas = Array.new
    salida = Casilla.new("Salida")
    @casillas.push(salida)
     
    @porSalida=0
    @tieneJuez = false
  end
  
  def correcto
    resultado=false
    resultado=true if (@casillas.length() > @numCasillaCarcel && @tieneJuez == true)
    return resultado
  end
  
  def correcto2(numCasilla)
    resultad=false
    if correcto() == true && numCasilla < @casillas.length()
      resultad=true
    end
    return resultad
  end
  
  def get_por_salida
    resultado=@porSalida
    if(@porSalida>0)
      @porSalida=@porSalida-1
    end
    return resultado
  end
  
  def aniade_casilla(casilla)
    if @casillas.length== @numCasillaCarcel
      carcel=Casilla.new("Carcel")
      @casillas.push(carcel)
    end
    if casilla.instance_of? Casilla_juez
      aniade_juez()
    else
      @casillas.push(casilla)
    end
    if @casillas.length== @numCasillaCarcel
      carcel=Casilla.new("Carcel")
      @casillas.push(carcel)
    end
  end
  
  def aniade_juez
    if @tieneJuez==false
      juez = Casilla_juez.new(numCasillaCarcel, "Juez")
      @casillas.push(juez)
      @tieneJuez=true
    end
  end
  
  def get_casilla(numCasilla)
    return @casillas.at(numCasilla)
  end
  
  def nueva_posicion(actual, tirada)
    if correcto()==false
      resultado=-1
    else
      resultado=actual+tirada
      if correcto2(resultado)==false
        aux=resultado- @casillas.length
        resultado=aux
      end
    end
    if resultado != actual+tirada
      @porSalida=@porSalida+1
    end
    return resultado
  end
  
  def calcular_tirada(origen, destino)
    resultado=destino-origen 
    if resultado<0
      resultado=resultado +@casillas.length
    end
    return resultado
  end
  
  attr_accessor :casillas, :salida, :numCasillaCarcel, :porSalida
  
  private :correcto
end

end