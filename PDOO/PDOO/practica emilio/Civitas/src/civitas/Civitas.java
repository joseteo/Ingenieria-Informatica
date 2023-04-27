/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author emilio
 */
public class Civitas {

    /**
//     * @param args the command line arguments
//     */
//    public static void main(String[] args) {
//        // TODO code application logic here
//        TipoCasilla tip=TipoCasilla.CALLE;
//        Casilla par1=new Casilla("Aguacate", 10,100, 20);
//        par1.setNumCasas();
//        //CON LA OTRA MANERA DE HACERLO
//        Casilla par2=new Casilla("MArrao", 30,200, 30);
//        System.out.println(par1);
//        System.out.println(par1.getNumCasas());
//        System.out.println(par2);
//        System.out.println(par2.getNumCasas());
//        
//        Casilla par3=par1;
//        System.out.println("igualdad");
//        System.out.println(par1.igualdadIdentidad(par3));
//        System.out.println("desigualdad");
//        System.out.println(par1.igualdadIdentidad(par2));
//        
//        System.out.println();
//        System.out.println("Quien empieza");
//        //Ejercicio 1
//        //lanzar dado para ver quien empieza
//        for(int i=0; i<10;i++){
//            System.out.print(Dado.getInstance().quienEmpieza(4) + " ");
//        }
//        //Ejercicio 2
//        //tiradas normales
//        System.out.println();
//        System.out.println("Tiradas del dado");
//        for(int i=0; i<10;i++){
//            System.out.print(Dado.getInstance().tirar() + " ");
//        }
//        //tiradas modo debug
//        Dado.getInstance().setDebug(true);
//        System.out.println();
//        System.out.println("Tiradas del dado");
//        for(int i=0; i<10;i++){
//            System.out.print(Dado.getInstance().tirar() + " ");
//        }
//        Dado.getInstance().setDebug(false);
//        //tiradas normales
//        System.out.println();
//        System.out.println("Tiradas del dado");
//        for(int i=0; i<10;i++){
//            System.out.print(Dado.getInstance().tirar() + " ");
//        }
//        
//        //Ejercicio 3
//        //prueba getUltimoResultado
//        System.out.println();
//        System.out.println("Ultimo resultado");
//        System.out.println(Dado.getInstance().getUltimoResultado());
//        //Ejercicio4 prueba los enumerados
//        System.out.println("tipos de enumerados");
//        System.out.println(TipoSorpresa.PAGARCOBRAR);
//        System.out.println(TipoCasilla.CALLE);
//        //Ejercicio 7 prueba la clase DIARIO
//        System.out.println("Diario");
//        System.out.println(Diario.getInstance().getEventos());
//      
//        
//     
//        
//        
//        
//        
//    }
//    
    private static void pruebaHotelAlquiler () {
      int i;  // Un contador para los bucles
        
//      # Nos preparamos un par de nombres para tener dos jugadores
      
      ArrayList<String> nombres = new ArrayList<>();
      nombres.add ("Vilma");
      nombres.add ("Pedro");
      
//      # Instanciamos un juego y obtenemos el diario
      // En mi versión puedo poner el modo debug al instanciar el juego (el boolean del segundo parámetro)
      boolean debug=true;
      CivitasJuego juego = new CivitasJuego (nombres,debug); 
      Diario diario = Diario.getInstance();
      
//      # Se implementa la prueba usando métodos de CivitasJuego y de Diario. Se le envían los mensajes a dichas variables.
      
//      # Durante el transcurso de la prueba se pueden escribir cosas en el diario
      diario.ocurreEvento("Turno de " + juego.getJugadorActual().getNombre());
      
//      # EMPEZAMOS A JUGAR.

//      # Avanzamos al primer jugador 
//      # Recordar que avanzar un jugador es que tire el dado (saldrá 1 al estar en modo debug)
//      # llegue a esa casilla, y le ocurra todo lo que pueda ocurrirle de manera automática
//      # Eso es lo que hace el método  avanza_jugador
      juego.avanzaJugador();
      
//      # Lo que requiere intervención del usuario hay que programarlo
//      # Hay que comprar la propiedad e intentar construir 5 casas
      juego.comprar();
      for (i=0; i<5; i++) {
        juego.construirCasa(0); //# Como solo tiene una propiedad, su índice es el cero
      }
      juego.construirHotel(0);
      juego.construirHotel(0);
//      # Si el juego está bien, este jugador solo tendrá 1 hotel, ya que la 5a casa no debe haberse
//      # edificado y el segundo hotel tampoco
      
//      # Cuanto más completa sea la información que metemos en el diario y la que muestran los métodos toString,
//      # más información tenemos en el momento de las pruebas para comprobar el correcto funcionamiento del software
      
//      # Aunque siempre podemos ver el estado de los objetos que queremos comprobar
      System.out.println (juego.getJugadorActual().toString());
      
//      # Una vez el primer jugador ha completado su turno con todas las operaciones que queríamos probar
//      # pasamos de turno
      juego.pasarTurno();
      
//      # Para el siguiente jugador, se pide simplemente que juegue, es decir, que avance
//      # Se anota su turno en el diario
//      # Se muestra su estado, para ver si ha pagado el alquiler. Debería haberlo hecho ya que 
//      # ha caído en la casilla de su oponente, y el pago del alquiler es algo que ocurre automáticamente
//      # al no requerir intervención expresa del usuario
      diario.ocurreEvento("Turno de " + juego.getJugadorActual().getNombre());
      juego.avanzaJugador();
      System.out.println (juego.getJugadorActual().toString());
      
//      # Acabamos comprobando el estado del primer jugador
      juego.pasarTurno();
      System.out.println (juego.getJugadorActual().toString());
            
//      # Por último, mostramos todo lo que se ha ido añadiendo al diario,
//      # Aunque esta operación puede hacerse en cualquier momento para leer el diario después de
//      # haber hecho alguna operación importante
      while (diario.eventosPendientes()) {
        System.out.println (diario.leerEvento());
      }

    }

    public static void main (String[] args) {
      pruebaHotelAlquiler();
    }
}
