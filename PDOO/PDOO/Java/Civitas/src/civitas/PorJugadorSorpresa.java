
package civitas;

import java.util.ArrayList;


public class PorJugadorSorpresa extends Sorpresa{
    
    private final String porjugador= "porjugador";
     
    void aplicarAJugador_porJugador(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            Sorpresa s1 = new Sorpresa(TipoSorpresa.PAGARCOBRAR, valor * -1, "PAGARCOBRAR");
            for (int i = 0; i < actual; i++){
                s1.aplicarAJugador(i, todos);
            }
            for (int i = actual + 1; i < todos.size(); i++){
                s1.aplicarAJugador(i, todos);
            }
            Sorpresa s2 = new Sorpresa(TipoSorpresa.PAGARCOBRAR, valor * (todos.size() - 1), "PAGARCOBRAR");
            s2.aplicarAJugador(actual, todos);
        }
    }
    
    public String porjugador(){
        return porjugador;
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
