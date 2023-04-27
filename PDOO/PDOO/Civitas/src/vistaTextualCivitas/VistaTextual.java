package vistaTextualCivitas;

import civitas.Casilla;
import civitas.CivitasJuego;
import civitas.Diario;
import civitas.OperacionJuego;
import controladorCivitas.Respuesta;
import civitas.OperacionInmobiliaria;
import civitas.Jugador;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;



public class VistaTextual implements Vista {
  
    
  private static String separador = "=====================";
  
  private Scanner in;
  
  CivitasJuego juegoModel;
  
  public VistaTextual (CivitasJuego juegoModel) {
    in = new Scanner (System.in);
    this.juegoModel=juegoModel;
  }
  
  
           
  @Override
  public  void pausa() {
    System.out.print ("\nPulsa una tecla");
    in.nextLine();
  }

  int leeEntero (int max, String msg1, String msg2) {
    Boolean ok;
    String cadena;
    int numero = -1;
    do {
      System.out.print (msg1);
      cadena = in.nextLine();
      try {  
        numero = Integer.parseInt(cadena);
        ok = true;
      } catch (NumberFormatException e) { // No se ha introducido un entero
        System.out.println (msg2);
        ok = false;  
      }
      if (ok && (numero < 0 || numero >= max)) {
        System.out.println (msg2);
        ok = false;
      }
    } while (!ok);

    return numero;
  }

  int menu (String titulo, ArrayList<String> lista) {
    String tab = "  ";
    int opcion;
    System.out.println (titulo);
    for (int i = 0; i < lista.size(); i++) {
      System.out.println (tab+i+"-"+lista.get(i));
    }

    opcion = leeEntero(lista.size(),
                          "\n"+tab+"Elige una opción: ",
                          tab+"Valor erróneo");
    return opcion;
  }
  
  @Override
  public void actualiza(){
      if(!juegoModel.finalDelJuego()){
        System.out.println(separador + "\nESTADO ACTUAL DEL JUEGO\n" + separador);
        System.out.println (separador + "\nJugadorActual = "+ juegoModel.getJugadorActual().toString());
      }else{
        System.out.println(juegoModel.ranking());
      }
  }

    @Override
    public Respuesta comprar(){
        int opcion = menu ("Elige si desea comprar la calle a la que se ha llegado", new ArrayList<> (Arrays.asList("NO","SI")));
        return (Respuesta.values()[opcion]);
    }

    @Override
    public OperacionInmobiliaria elegirOperacion(){
        int opcion = menu("Elige la gestión inmobiliaria que deseas realizar", new ArrayList<> (Arrays.asList("CONSTRUIR_CASA","CONSTRUIR_HOTEL","TERMINAR")));
        return (OperacionInmobiliaria.values()[opcion]);
    }

    @Override
    public int elegirPropiedad(){
        ArrayList<String> lista = new ArrayList<>();
        for(int i=0; i < juegoModel.getJugadorActual().getPropiedades().size(); i++){
            lista.add(juegoModel.getJugadorActual().getPropiedades().get(i).getNombre());
        }
        int opcion = menu("Cuál es la propiedad del jugador actual sobre la que se desea realizar la gestion", lista);
        return opcion;
    }

    @Override
    public void mostrarSiguienteOperacion(OperacionJuego operacion) {
        System.out.println ("La siguiente operacion que va a realizar el juego es "+ operacion);
    }

    @Override
    public void mostrarEventos() {
        while (Diario.getInstance().eventosPendientes()){
          System.out.println ("Eventos pendientes = "+Diario.getInstance().leerEvento());
      }
    }

}
