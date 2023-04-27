
package juegoTexto;


import civitas.CivitasJuego;
import civitas.Dado;
import java.util.ArrayList;


public class JuegoTexto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        VistaTextual vista = new VistaTextual();
        
        ArrayList<String> nombres = new ArrayList<>();
        nombres.add("Jugador1");
        nombres.add("Jugador2");
        nombres.add("Jugador3");
        nombres.add("Jugador4");
        CivitasJuego juego = new CivitasJuego(nombres);
        
        Dado.getInstance().setDebug(true);
        
        Controlador controlador = new Controlador(juego, vista);
        
        controlador.juega();
    }
    
}
