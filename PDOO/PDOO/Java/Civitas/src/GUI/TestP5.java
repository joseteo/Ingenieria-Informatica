
package GUI;

import civitas.*;
import GUI.*;
import java.util.*;

public class TestP5 {
    
    public static void main(){
        
        CivitasView civitasview;
        civitasview = new CivitasView();
        Dado.createInstance(civitasview);
        CapturaNombres capturanombres;
        capturanombres = new CapturaNombres(civitasview, true);
        ArrayList<String> nombres;
        nombres = capturanombres.getNombres();
        CivitasJuego civitasjuego;
        civitasjuego = new CivitasJuego(nombres);
        Controlador controlador;
        controlador = new Controlador(civitasjuego, civitasview);
        
        
    }
}
