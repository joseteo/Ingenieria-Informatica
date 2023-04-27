
package civitas;
import java.util.ArrayList;

public abstract class Sorpresa {
    private String texto;
    
    
    abstract void aplicarAJugador(int actual, ArrayList<Jugador> todos);
    
    
    void informe(int actual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("Se esta aplicando una sorpresa al jugador " + todos.get(actual).getNombre() +
                ", \nLa informacion de la sorpresa es "+toString());
    }
    
    public Boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos){
        Boolean resultado = false;
        if (actual >= 0 && actual < todos.size()){
            resultado = true;
        }
        return resultado;
    }
    
    String getTexto(){
        return texto;
    }
    
    Sorpresa(String texto){
        this.texto = texto;
    }
    
    @Override
    public String toString(){
        return "Sorpresa{" + "texto=" + texto + "}";
    }
    
    
}
