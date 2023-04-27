/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;



import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import GUI.*;

/**
 *
 * @author emilio
 */
public class CivitasJuego {
    //Relaciones
    private EstadoJuego estado;
    private GestorEstados gestor;
    private Tablero tablero;
    private MazoSorpresas mazo;
    private ArrayList<Jugador> jugadores;
    
    int turnos=0;
    
    //Atributos de instancia
    private int indiceJugadorActual;
    
    //Metodos
    
    public void avanzaJugador(){
        Jugador jugadorActual = getJugadorActual();
        int posicionActual=jugadorActual.getCasillaActual();
        int tirada = Dado.getInstance().tirar();
        int posicionNueva=this.tablero.nuevaPosicion(posicionActual, tirada);
        Casilla casilla = tablero.getCasilla(posicionNueva);
        casilla.tramitarAlquiler(jugadorActual);
        this.contabilizarPasosPorSalida(jugadorActual);
        jugadorActual.moverACasilla(posicionNueva);
        casilla.recibeJugador(indiceJugadorActual, jugadores);  
    }
    
    
    public CivitasJuego(ArrayList<String> nombres){
       this.jugadores = new ArrayList<>();
       Jugador jug;
       for(int i=0; i<nombres.size();i++){
           jug=new Jugador(nombres.get(i));
           jugadores.add(jug);
       }
       
       this.gestor= new GestorEstados();
       this.estado=this.gestor.estadoInicial();
       Dado.getInstance().setDebug(false);
       
       this.indiceJugadorActual=Dado.getInstance().quienEmpieza(nombres.size()-1);
       mazo=new MazoSorpresas();
       this.tablero= new Tablero();
       this.inicializaTablero(mazo);
       this.inicializaMazoSorpresas(tablero);
       
    }
    public CivitasJuego(ArrayList<String> nombres, boolean debug){
       this.jugadores = new ArrayList<>();
       Jugador jug;
       for(int i=0; i<nombres.size();i++){
           jug=new Jugador(nombres.get(i));
           jugadores.add(jug);
       }
       
       this.gestor= new GestorEstados();
       this.estado=this.gestor.estadoInicial();
       Dado.getInstance().setDebug(debug);
       
       this.indiceJugadorActual=Dado.getInstance().quienEmpieza(nombres.size()-1);
       mazo=new MazoSorpresas();
       this.tablero= new Tablero();
       this.inicializaTablero(mazo);
       this.inicializaMazoSorpresas(tablero);
       
    }
    
    public boolean comprar(){
        boolean res;
        Jugador jugadorActual=getJugadorActual();
        int numCasillaActual= jugadorActual.getCasillaActual();
        Casilla casilla = tablero.getCasilla(numCasillaActual);
        res=jugadorActual.comprar(casilla);
        return res;
    }
    
    public boolean construirCasa(int ip){
        Jugador jug=jugadores.get(indiceJugadorActual);
        return jug.construirCasa(ip);
    }
    
    public boolean construirHotel(int ip){
        Jugador jug=jugadores.get(indiceJugadorActual);
        return jug.construirHotel(ip);
    }
    private void contabilizarPasosPorSalida(Jugador jugadorActual){
        while(tablero.computarPasoPorSalida()){
            jugadorActual.pasaPorSalida();
        }
    }
        
    public boolean finalDelJuego(){
        
        boolean enBan=false;
        
        for(int i=0; i<jugadores.size(); i++){
            if(jugadores.get(i).enBancarrota()){
                enBan=true;
            }
        }
        return enBan;
    }
    //Metodo para poder devolver el jugador actual
    public Jugador getJugadorActual(){
        Jugador jug=jugadores.get(indiceJugadorActual);
        return jug;
        
    }
    
    public int getIndiceJugadorActual(){
        return this.indiceJugadorActual;
    }
    public ArrayList<Jugador> getJugadores(){
        return this.jugadores;
    }
    
    public Tablero getTablero(){
        return this.tablero;
    }
    
    private void inicializaMazoSorpresas(Tablero tablero){
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR,"Impuesto Endesa",-500));
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR,"Multa de tráfico",-300));
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR,"Hacienda somos todos",-200));

        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR,"Herencia Abuelos",400));
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR,"Loteria y Apuestas el Estado",500));
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR,"Beca UGR",200));
        
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PORCASAHOTEL,"Realizar Reformas en todas tus casas y hoteles",-100));
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PORCASAHOTEL,"Hay una fuga de agua y tu vecino se queja de tu seguro",-150));
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PORCASAHOTEL,"Aumento del precio de tus viviendas",120));
        this.mazo.alMazo(new Sorpresa(TipoSorpresa.PORCASAHOTEL,"Revalorizacion del Euribor",80));
        
        
        
    }
    
    private void inicializaTablero(MazoSorpresas mazo){
        
        //this.tablero.añadeCasilla(new Casilla("Sorpresa",mazo)); //casilla sorpresa
        this.tablero.añadeCasilla(new Casilla("Pajaritos",160,75,50));
        this.tablero.añadeCasilla(new Casilla("Rio Beiro",180,80,60));
        this.tablero.añadeCasilla(new Casilla("Sorpresa",mazo)); //casilla sorpresa
        this.tablero.añadeCasilla(new Casilla("Plazo Toros",200,95,70));
        this.tablero.añadeCasilla(new Casilla("Cartuja",230,100,80 ));
        
        this.tablero.añadeCasilla(new Casilla("Gonzalo Gallas",210,100,80));
        this.tablero.añadeCasilla(new Casilla("Pedro Antonio",220,110,90));
        this.tablero.añadeCasilla(new Casilla("Sorpresa",mazo)); //casilla sorpresa
        this.tablero.añadeCasilla(new Casilla("Camino Ronda",230,120,110));
        this.tablero.añadeCasilla(new Casilla("Arabial",250,135,130));
        
        this.tablero.añadeCasilla(new Casilla("Plaza de Gracia",240,130,120));
        this.tablero.añadeCasilla(new Casilla("Sorpresa",mazo)); //casilla sorpresa
        this.tablero.añadeCasilla(new Casilla("Alhamar",260,120,100));
        this.tablero.añadeCasilla(new Casilla("Neptuno",280,150,150));
        this.tablero.añadeCasilla(new Casilla("Recogidas",300,180,160));
        this.tablero.añadeCasilla(new Casilla("Sorpresa",mazo)); //casilla sorpresa
        
        this.tablero.añadeCasilla(new Casilla("Gran Via de Colon",400,220,280));
        this.tablero.añadeCasilla(new Casilla("Reyes Católicos",420,230,300));
       
        
        
        
        
    }
    
    public void pasarTurno(){
       
       indiceJugadorActual++;
       if(jugadores.size() == indiceJugadorActual){
           indiceJugadorActual=0;
       }
    }
    
    public ArrayList<Jugador> ranking(){
        ArrayList<Jugador> aux = jugadores;
        Collections.sort(aux);
        return aux;
//        //Creamos un arraylist auxiliar de jugadores.
//        ArrayList<Jugador> aux= new ArrayList<>(jugadores);
//        //Creamos dos jugadores para compararlos
//        Jugador jugComp;
//        Jugador jugMax;
//        
//        
//        for(int i=0;i<jugadores.size()-2;i++){
//            //Jugador que pondremos como mayor saldo el jugadorMAx
//            jugMax=jugadores.get(i);
//            for(int j=i; j < jugadores.size()-1;j++){
//                //Jugador que comparamos
//                
//                jugComp=jugadores.get(j);
//                //utilizamos la funcion comparteTo modificada para los saldos
//                if(jugMax.compareTo(jugComp) == -1){
//                    //si el jugador jugMax tiene menos sueldo
//                    //los intercambiamos
//                    aux.set(i, jugComp);
//                    aux.set(j, jugMax);
//                    //ponemos ahora el jugador max como el que hemos comparado
//                    jugMax=jugComp;
//                    
//                }
//            }
//            
//        }
//        return aux;
//        
//        
    }
    
    //funcion que da a cada jugador dos turnos seguidos
//    public OperacionJuego siguientePaso(){
//        Jugador jugadorActual=getJugadorActual();
//        OperacionJuego operacion = gestor.siguienteOperacion(jugadorActual, estado);
//        if(turnos<2){
//            //si queremos pasar turno
//            //estado = EstadoJuego.DESPUES_GESTIONAR;
//            estado = EstadoJuego.INICIO_TURNO;
//            operacion = gestor.siguienteOperacion(jugadorActual, estado);
//            turnos++;
//        }else{
//            turnos=0;
//        }
//            
//            if(operacion == OperacionJuego.AVANZAR) {
//                this.avanzaJugador();
//                this.siguientePasoCompletado(operacion);
//            }else if (operacion == OperacionJuego.PASAR_TURNO){
//                this.pasarTurno();
//                this.siguientePasoCompletado(operacion);
//            }
//        
//            
//        return operacion;       
//    }
    
    
    public OperacionJuego siguientePaso(){
        Jugador jugadorActual=getJugadorActual();
        OperacionJuego operacion = gestor.siguienteOperacion(jugadorActual, estado);
        if(operacion == OperacionJuego.AVANZAR) {
            this.avanzaJugador();
            this.siguientePasoCompletado(operacion);
        }else if (operacion == OperacionJuego.PASAR_TURNO){
            this.pasarTurno();
            this.siguientePasoCompletado(operacion);
        }
            
        return operacion;       
    }
    
    public void siguientePasoCompletado(OperacionJuego operacion){
        Jugador jug=jugadores.get(indiceJugadorActual);
        estado = gestor.siguienteEstado(jug, estado, operacion);
    }
   
    public String toString() {
		
 	return "El jugador " + jugadores.get(indiceJugadorActual).toString() + ", esta en la casilla: " + tablero.toString();
    }	
    
    
    
    
    
    
}
