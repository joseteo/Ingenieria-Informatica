/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

/**
 *
 * @author teo
 */
public class JugadorEspeculador extends Jugador{
    
    static int FactorEspeculador = 2;

    public JugadorEspeculador(Jugador jugador) {
        super(jugador);
        actualizaPropiedadesPorConversion(this);
    }
    
    public int getFactorEspeculador(){
        return FactorEspeculador;
    }
    
    @Override
    int getHotelesMax(){
        return (super.getHotelesMax() * FactorEspeculador );
    }
    
    @Override
    int getCasasMax(){
        return (super.getCasasMax() * FactorEspeculador );
    }
    
    @Override
    boolean construirCasa(int ip){
        boolean result = false;
        result = super.construirCasa(ip);
        this.recibe(getPropiedades().get(ip).getPrecioEdificar()/2);
        return result;
    }
    
    @Override
    boolean construirHotel(int ip){
        boolean result = false;
        result = super.construirHotel(ip);
        this.recibe(getPropiedades().get(ip).getPrecioEdificar()/2);
        return result;
    }
    
    public void actualizaPropiedadesPorConversion(Jugador jugador){
        
        for(int i = 0; i < jugador.getPropiedades().size(); i++){
            jugador.getPropiedades().get(i).actualizaPropietarioPorConversion(this);
        }
    }
    
    
    
}
