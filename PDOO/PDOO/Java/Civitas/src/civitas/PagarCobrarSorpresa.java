
package civitas;

import java.util.ArrayList;


public class PagarCobrarSorpresa extends Sorpresa{
    
    private final String pagarcobrar= "pagarcobrar";
     
    void aplicarAJugador_pagarCobrar(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            //informe(actual, todos);
            todos.get(actual).modificarSaldo(valor);
        }
    }
    
    public String pagarcobrar(){
        return pagarcobrar;
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
