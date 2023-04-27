import vistaTextualCivitas.VistaTextual;
import GUI.Vista;
import controladorCivitas.Controlador;
import civitas.CivitasJuego;
import civitas.Casilla;
import controladorCivitas.Dado;
import civitas.Diario;
import civitas.TipoCasilla;
import civitas.TipoSorpresa;
import java.util.ArrayList;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author emilio
 */
public class JuegoTexto {
    
   
    public static void main(String[] args) {
        // TODO code application logic here
        ArrayList<String> jugadores= new ArrayList<>();
        jugadores.add("Pepe");
        jugadores.add("Emilio");
        jugadores.add("Juan");
        
        CivitasJuego juego= new CivitasJuego(jugadores,true);

        Vista vista= new VistaTextual(juego);
        Controlador controlador = new Controlador(juego, vista);
        

        controlador.juega();
        
        
        
    }
    
    
    
    
    
}
