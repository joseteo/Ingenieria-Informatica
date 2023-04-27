
package JuegoTexto;

import civitas.CivitasJuego;
import civitas.GestionesInmobiliarias;
import civitas.Jugador;
import civitas.OperacionInmobiliaria;
import civitas.OperacionesJuego;
import civitas.Respuestas;
import civitas.SalidasCarcel;
import java.util.ArrayList;


public class Controlador {
    private CivitasJuego juego;
    private VistaTextual vista;
    
    Controlador(CivitasJuego juego, VistaTextual vista){
        this.juego = juego;
        this.vista = vista;
    }
    
    void juega(){
        vista.setCivitasJuego(juego);
        while (!juego.finalDelJuego()){
            vista.actualizarVista();
            
            vista.pausa();
            
            OperacionesJuego operacionSig = juego.siguientePaso();
            vista.mostrarSiguienteOperacion(operacionSig);
            
            if (operacionSig != OperacionesJuego.PASAR_TURNO){
                vista.mostrarEventos();
            }
            
            Boolean finJuego = juego.finalDelJuego();
            
            if (finJuego != true){
                switch (operacionSig){
                    case COMPRAR:
                        Respuestas resp = vista.comprar();
                        if (resp == Respuestas.SI){
                           juego.comprar();
                        }
                        juego.siguientePasoCompletado(operacionSig);
                        break;
                    case GESTIONAR:
                        vista.gestionar();
                        GestionesInmobiliarias gest = GestionesInmobiliarias.values()[vista.getGestion()];
                        int ip = vista.getPropiedad();
                        OperacionInmobiliaria op = new OperacionInmobiliaria(gest, ip);
                        switch (op.getGestion()){
                            case VENDER:
                                juego.vender(vista.getPropiedad());
                                break;
                            case HIPOTECAR:
                                juego.hipotecar(vista.getPropiedad());
                                break;
                            case CANCELAR_HIPOTECA:
                                juego.cancelarHipoteca(vista.getPropiedad());
                                break;
                            case CONSTRUIR_CASA:
                                juego.construirCasa(vista.getPropiedad());
                                break;
                            case CONSTRUIR_HOTEL:
                                juego.construirHotel(vista.getPropiedad());
                                break;
                            case TERMINAR:
                                juego.siguientePasoCompletado(operacionSig);
                                break;
                        }
                        break;
                    case SALIR_CARCEL:
                        SalidasCarcel sal = vista.salirCarcel();
                        if (sal == SalidasCarcel.PAGANDO)
                            juego.salirCarcelPagando();
                        else if (sal == SalidasCarcel.TIRANDO)
                            juego.salirCarcelTirando();
                        juego.siguientePasoCompletado(operacionSig);
                        break;
                }
            }
            
        }
        ArrayList<Jugador> ranking = juego.ranking();
        System.out.println("RANKING");
        for (int i = 0; i < ranking.size(); i++){
            System.out.println(i+1);
            System.out.println(ranking.get(i).toString());
        }
        
        
    }
}
