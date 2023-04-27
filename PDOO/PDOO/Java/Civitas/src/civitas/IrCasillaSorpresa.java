
package civitas;

import java.util.ArrayList;

 
public class IrCasillaSorpresa extends Sorpresa{
    
    private final String ircasilla= "ircasilla";
    
    IrCasillaSorpresa(String tipo, Tablero tablero, int valor, String texto){
        //Para constuir la sorpresa que envia al jugador a otra casilla
        init();
        this.tipo = tipo;
        this.tablero = tablero;
        this.valor = valor;
        this.texto = texto;
    }
     
    @Override
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            //informe(actual, todos);
            int casillaActual = todos.get(actual).getNumCasillaActual();
            int tirada = tablero.calcularTirada(casillaActual, valor);
            int nuevaPosicion = tablero.nuevaPosicion(casillaActual, tirada);
            todos.get(actual).moverACasilla(nuevaPosicion);
            tablero.getCasilla(valor).recibeJugador(actual, todos);
        }
    }
    
    public String ircasilla(){
        return ircasilla;
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
