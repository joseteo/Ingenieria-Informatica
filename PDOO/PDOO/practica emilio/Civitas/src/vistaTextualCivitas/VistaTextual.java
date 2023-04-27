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
import GUI.Vista;



public class VistaTextual implements Vista {
  
    
  private static String separador = "=====================";
  
  private Scanner in;
  
  CivitasJuego juegoModel;
  
  private Respuesta respuestas;
  private int iPropiedad;
  private int iGestion;
  
  public VistaTextual (CivitasJuego juegoModel) {
    in = new Scanner (System.in);
    
    this.juegoModel=juegoModel;
  }
  
  
           
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
  
    /**
     *
     * @return
     */
    @Override
  public Respuesta comprar(){
        int opcion;
        ArrayList<String>resp=new ArrayList<>();
        resp.add("SI");
        resp.add("NO");
        opcion = menu("¿quiere comprar?",resp);
      switch (opcion) {
          case 0:
              return Respuesta.SI;
          case 1:
              return Respuesta.NO;
          default:
              return null;
      }
        
    }
  
  
  //Metodos Vistas
  public void actualiza(){
      this.juegoModel.toString();
  }
  
    /**
     *
     * @return
     */
    @Override
  public OperacionInmobiliaria elegirOperacion(){
      int opcion;
      ArrayList<String>resp=new ArrayList<>();
      resp.add("Construir Casa");
      resp.add("Construir Hotel");
      resp.add("Terminar");

      opcion = menu("¿Que operación inmobiliaria quiere realizar",resp);
      switch (opcion) {
          case 0:
              System.out.println("Voy a construir una casa");
              return OperacionInmobiliaria.CONSTRUIR_CASA;
              
          case 1:
              System.out.println("voy a construir un hotel");
              return OperacionInmobiliaria.CONSTRUIR_HOTEL;
              
          case 2:
              System.out.println("Le has dado a terminar");
              return OperacionInmobiliaria.TERMINAR;
          default:
              return null;
      }
      
  }
  //revisar en clase...

    /**
     *
     * @return
     */
  @Override
  public int elegirPropiedad(){
      int numJug=juegoModel.getIndiceJugadorActual();
      Jugador jug = this.juegoModel.getJugadores().get(numJug);
      ArrayList<String> propiedadesJugador = new ArrayList<>();
      for(int i=0;i<jug.getPropiedades().size();i++){
          propiedadesJugador.add(jug.getPropiedades().get(i).getNombre());
      }
      String comparacion;
      int opcion =menu("Elige la propiedad a gestionar: ", propiedadesJugador);
      System.out.println("Imprime la opcion");
      System.out.println(opcion);
      comparacion =propiedadesJugador.get(opcion);
      for(int j=1;j<jug.getPropiedades().size();j++){
          
          System.out.println(jug.getPropiedades().get(j).getNombre());
          String comp=jug.getPropiedades().get(j).getNombre();
          if(comparacion == comp){
              opcion = j;
              j=jug.getPropiedades().size()-1;
          }
                  
      }
      return opcion;
  }
  
    /**
     *
     * @param operacion
     */
    @Override
  public void mostrarSiguienteOperacion(OperacionJuego operacion){
      System.out.println(operacion);
  }
  
    /**
     *
     */
    @Override
  public void mostrarEventos(){
      while(Diario.getInstance().eventosPendientes()){
          System.out.println(Diario.getInstance().leerEvento());
      }
  }

  public void mostrarEstado(){
      if(!this.juegoModel.finalDelJuego()){
          int numC = this.juegoModel.getJugadores().get(this.juegoModel.getIndiceJugadorActual()).getCasillaActual();
          
          System.out.println(this.juegoModel.getJugadores().get(this.juegoModel.getIndiceJugadorActual()));
      }else{
          this.juegoModel.ranking();
      }
  }
  

}
