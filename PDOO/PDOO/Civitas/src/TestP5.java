/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
import civitas.CivitasJuego;
import GUI.CivitasView;
import GUI.CapturaNombres;
import GUI.*;
import GUI.Vista;
import java.util.ArrayList;
import controladorCivitas.Controlador;
/**
 *
 * @author teo
 */
public class TestP5 {
    //Controlador controlador;
    //private CapturaNombres capNombres;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        CivitasView vistaCivitas=new CivitasView();
        
        CapturaNombres capNombres = new CapturaNombres(vistaCivitas, true);
        
        Dado.createInstance(vistaCivitas);
        
        ArrayList<String> nombres=new ArrayList();
        nombres=capNombres.getNombres();
        
        CivitasJuego juego=new CivitasJuego(nombres,false);
        
        Controlador controlador = new Controlador(juego, vistaCivitas);
        vistaCivitas.setCivitasJuego(juego);
        
        controlador.juega();
        
        
        
        
        
    }
    
}
