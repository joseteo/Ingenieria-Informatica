/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author teo
 */
import civitas.CivitasJuego;
import controladorCivitas.ControladorMIO;
import java.util.ArrayList;
import vistaTextualCivitas.VistaTextual;

public class JuegoTexto {
    
    public static void main(String[] args){
        
        ArrayList<String> nombres = new ArrayList<>();
        nombres.add("Jugador1");
        nombres.add("Jugador2");
        nombres.add("Jugador3");
        nombres.add("Jugador4");
        
        CivitasJuego juego = new CivitasJuego(nombres, false);
        
        VistaTextual vista = new VistaTextual(juego);
        
        ControladorMIO controlador = new ControladorMIO(juego, vista);
        
        controlador.juega();
    }
}
