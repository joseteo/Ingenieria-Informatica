
package civitas;

import java.util.ArrayList;

public class IrCarcelSorpresa extends Sorpresa {
    private final String ircarcel= "ircarcel";
    public Tablero tablero;
    
    IrCarcelSorpresa(String tipo, Tablero tablero){
        //Para constuir la sorpresa que envia a la carcel
        this.tablero = tablero;
        super.texto = "Debes ir a la carcel";
    }
    
     
    void aplicarAJugador_irCarcel(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            todos.get(actual).encarcelar(tablero.getCarcel());
        }
    }
    
    public String ircarcel(){
        return ircarcel;
    }
    
    public Boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos){
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
