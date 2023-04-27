
package juegoTexto;


import civitas.CivitasJuego;
import civitas.Diario;
import civitas.OperacionesJuego;
import civitas.SalidasCarcel;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import civitas.Casilla;
import civitas.Jugador;
import civitas.Respuestas;
import civitas.TituloPropiedad;

class VistaTextual {
  
  CivitasJuego juegoModel; 
  int iGestion=-1;
  int iPropiedad=-1;
  private static String separador = "=====================";
  
  private Scanner in;
  
  VistaTextual () {
    in = new Scanner (System.in);
  }
  
  void mostrarEstado(String estado) {
    System.out.println (estado);
  }
              
  void pausa() {
    System.out.print ("Pulsa una tecla");
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

  SalidasCarcel salirCarcel() {
    int opcion = menu ("Elige la forma para intentar salir de la carcel",
      new ArrayList<> (Arrays.asList("Pagando","Tirando el dado")));
    return (SalidasCarcel.values()[opcion]);
  }

  Respuestas comprar() {
    int opcion = menu ("Elige si desea comprar la calle a la que se ha llegado",
      new ArrayList<> (Arrays.asList("NO","SI")));
    return (Respuestas.values()[opcion]);
  }

  void gestionar () {
      iGestion = menu ("¿Cuál es el número de gestion inmobiliaria elegida?",
              new ArrayList<> (Arrays.asList("VENDER","HIPOTECAR","CANCELAR_HIPOTECA",
                      "CONSTRUIR_CASA","CONSTRUIR_HOTEL","TERMINAR")));
      ArrayList<String> lista;
      lista = new ArrayList<>();
      for (int i = 0; i < juegoModel.getJugadorActual().getPropiedades().size(); i++){
          lista.add(juegoModel.getJugadorActual().getPropiedades().get(i).nombre.toString());
      }
      iPropiedad = menu ("¿Cuál es la propiedad del jugador actual sobre la que se desea "
              + "realizar la gestion", lista);
  }
  
  public int getGestion(){
      return iGestion;
  }
  
  public int getPropiedad(){
      return iPropiedad;
  }
    

  void mostrarSiguienteOperacion(OperacionesJuego operacion) {
      System.out.println ("La siguiente operacion que va a realizar el juego es "+ 
              operacion);
  }

  void mostrarEventos() {
      while (Diario.getInstance().eventosPendientes()){
          System.out.println ("Eventos pendientes = "+Diario.getInstance().leerEvento());
      }
  }
  
  public void setCivitasJuego(CivitasJuego civitas){ 
        juegoModel = civitas;
        actualizarVista();
  }
  
  void actualizarVista(){
      System.out.println(separador + "\nESTADO ACTUAL DEL JUEGO\n" + separador);
      System.out.println (separador + "\nJugadorActual = "+ juegoModel.getJugadorActual().toString());
      if (juegoModel.getJugadorActual().getPropiedades().size() > 0){
        System.out.println(separador + "\nSus propiedades =");
        for (int i = 0; i < juegoModel.getJugadorActual().getPropiedades().size(); i++ ){
            System.out.println(juegoModel.getJugadorActual().getPropiedades().get(i).toString());
        }
      } else {
            System.out.println(separador + "\nSus propiedades = No tiene ninguna propiedad");
      }
      
      System.out.println(separador + "\nCasillaActual = "+ juegoModel.getCasillaActual().toString() + "\n" + separador);
  } 
}