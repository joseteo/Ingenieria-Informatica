
package civitas;

import java.util.ArrayList;


public class PorCasaHotelSorpresa extends Sorpresa{
    
    private final String porcasahotel= "porcasahotel";
     
    void aplicarAJugador_porCasaHotel(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            //informe(actual, todos);
            todos.get(actual).modificarSaldo(valor * todos.get(actual).cantidadCasasHoteles());
        }
    }
    
    public String porcasahotel(){
        return porcasahotel;
    }
    
    @Override public Boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos){
        Boolean resultado = false;
        if (actual >= 0 && actual < todos.size()){
            resultado = true;
        }
        return resultado;
    }
    
    @Override public void informe(int actual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("se esta aplicando una sorpresa al jugador " + todos.get(actual).getNombre());
    }
}
