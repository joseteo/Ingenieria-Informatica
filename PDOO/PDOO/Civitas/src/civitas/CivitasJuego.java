/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package civitas;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author joseteo
 */
public class CivitasJuego {
    
    private int indiceJugadorActual;

    private MazoSorpresas mazo;
    private ArrayList<Jugador> jugadores;
    private EstadoJuego estado;
    private GestorEstados gestorEstados;
    private Tablero tablero;
    
    private void avanzaJugador(){
        Jugador jugadorActual = getJugadorActual();
        int posicionActual = jugadorActual.getCasillaActual();
        int tirada = Dado.getInstance().tirar();
        int posicionNueva = tablero.nuevaPosicion(posicionActual, tirada);
        Casilla casilla = tablero.getCasilla(posicionNueva);
        ContabilizarPasosPorSalida(jugadorActual);
        jugadorActual.moverACasilla(posicionNueva);
        casilla.recibeJugador(indiceJugadorActual, jugadores);
    }
    
    public CivitasJuego(ArrayList<String> nombres, boolean  debug){
        jugadores = new ArrayList<>();
        for (int i = 0; i < nombres.size(); i++){
            Jugador jugador = new Jugador(nombres.get(i));
            jugadores.add(jugador);
        }
        
        gestorEstados = new GestorEstados();
        estado = gestorEstados.estadoInicial();
        
        Dado.getInstance().setDebug(debug);
        
        indiceJugadorActual = Dado.getInstance().quienEmpieza(jugadores.size());
        
        mazo = new MazoSorpresas();
        
        inicializarTablero(mazo);
        inicializarMazoSorpresas();
    }
    
    public boolean comprar(){
        boolean res = false;
        
        Jugador jugadorActual = getJugadorActual();
        int numCasillaActual = jugadorActual.getCasillaActual();
        if(numCasillaActual != 3 && numCasillaActual != 5 
                && numCasillaActual != 8 && numCasillaActual != 14 
                && numCasillaActual != 17){
            
            Casilla casilla = tablero.getCasilla(numCasillaActual);
            CasillaCalle calle = (CasillaCalle)casilla;
            if(!calle.tienepropietario()){
                res = jugadorActual.comprar(calle);
            }
        }
        return res;
    }
    
    private void inicializarTablero(MazoSorpresas mazo){
        tablero = new Tablero();
        //casilla 0 es la de salida
        tablero.aniadeCasilla(new CasillaCalle("Calle 1", 500, 100, 150)); //casilla 1
        tablero.aniadeCasilla(new CasillaCalle("Calle 2", 520, 100, 200)); //casilla 2
        tablero.aniadeCasilla(new CasillaSorpresa("Sorpresa",mazo)); //casilla 3
        tablero.aniadeCasilla(new CasillaCalle("Calle 4", 550, 110, 300)); //casilla 4
        tablero.aniadeCasilla(new CasillaSorpresa("Sorpresa",mazo));//casilla 5
        tablero.aniadeCasilla(new CasillaCalle("Calle 6", 600, 120, 400)); //casilla 6
        tablero.aniadeCasilla(new CasillaCalle("Calle 7", 650, 130, 450)); //casilla 7
        tablero.aniadeCasilla(new CasillaSorpresa("Sorpresa",mazo)); //casilla 8
        tablero.aniadeCasilla(new CasillaCalle("Calle 9", 700, 140, 1000)); //casilla 9
        tablero.aniadeCasilla(new Casilla("Descanso")); //casilla 10
        tablero.aniadeCasilla(new CasillaCalle("Calle 11", 750, 150, 1100)); //casilla 11
        tablero.aniadeCasilla(new CasillaCalle("Calle 12", 800, 160, 1200)); //casilla 12
        tablero.aniadeCasilla(new CasillaCalle("Calle 13", 850, 170, 1300)); //casilla 13
        tablero.aniadeCasilla(new CasillaSorpresa("Sorpresa", mazo)); //casilla 14
        tablero.aniadeCasilla(new CasillaCalle("Calle 15", 900, 180, 1400)); //casilla 15
        tablero.aniadeCasilla(new CasillaCalle("Calle 16", 950, 190, 1500)); //casilla 16
        tablero.aniadeCasilla(new CasillaSorpresa("Sorpresa", mazo)); //casilla 17
        tablero.aniadeCasilla(new CasillaCalle("Calle 18", 1000, 200, 2000)); //casilla 18
    }
    
    private void inicializarMazoSorpresas(){
        mazo.alMazo(new SorpresaPagarCobrar("Has ganado el concurso de belleza, ganas 200 euros", 200));
        mazo.alMazo(new SorpresaPagarCobrar("Exceso de velocidad, pagas 100 euros de multa", -100));
        mazo.alMazo(new SorpresaPorCasaHotel("Ganas 100 euros por cada casa u hotel", 100));
        mazo.alMazo(new SorpresaPorCasaHotel("Pagas 50 euros por cada casa u hotel", -50));
        mazo.alMazo(new SorpresaConvertirme());
    }
    
    public int getIndiceJugadorActual(){
        return this.indiceJugadorActual;
    }
    
    public Jugador getJugadorActual(){
        return jugadores.get(indiceJugadorActual);
    }
    
    public ArrayList<Jugador> getJugadores(){
        return jugadores;
    }
    
    public Tablero getTablero(){
        return this.tablero;
    }
    
    private void pasarTurno(){
        indiceJugadorActual = (indiceJugadorActual + 1)% 4;
    }
    
    public OperacionJuego siguientePaso(){
        Jugador jugadorActual = getJugadorActual();
        OperacionJuego operacion = gestorEstados.siguienteOperacion(jugadorActual, estado);
        if (operacion == OperacionJuego.PASAR_TURNO){
            pasarTurno();
            siguientePasoCompletado(operacion);
        } else if (operacion == OperacionJuego.AVANZAR){
            avanzaJugador();
            siguientePasoCompletado(operacion);
        }
        return operacion;
    }
    
    public void siguientePasoCompletado(OperacionJuego operacion){
        estado = gestorEstados.siguienteEstado(jugadores.get(indiceJugadorActual), estado, operacion);
    }
    
    public boolean construirCasa(int ip){
        boolean resultado = jugadores.get(indiceJugadorActual).construirCasa(ip);
        return resultado;
    }
    
    public boolean construirHotel(int ip){
        boolean resultado = jugadores.get(indiceJugadorActual).construirHotel(ip);
        return resultado;
    }
    
    public boolean finalDelJuego(){
        boolean resultado = false;
        for (int i = 0; i < jugadores.size(); i++){
            if (jugadores.get(i).enBancarrota()){
                resultado = true;
            }
        }
        return resultado;
    }
    
    /*private*/ public ArrayList<Jugador> ranking(){
        ArrayList<Jugador> aux = jugadores;
        Collections.sort(aux);
        Collections.reverse(aux);
        return aux;
    }
        
    private void ContabilizarPasosPorSalida(Jugador jugadorActual){
        if (tablero.computarPasoPorSalida()){
            jugadorActual.pasaPorSalida();
        }
    }
    
}
