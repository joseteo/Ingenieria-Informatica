
package civitas;

import java.util.ArrayList;
import java.util.Collections;


public class CivitasJuego {
    private int indiceJugadorActual;
    
    private MazoSorpresas mazo;
    private Tablero tablero;
    private ArrayList<Jugador> jugadores;
    private EstadosJuego estado;
    private GestorEstados gestorEstados;
    
    private void avanzaJugador(){
        Jugador jugadorActual = jugadores.get(indiceJugadorActual);
        int posicionActual = jugadorActual.getNumCasillaActual();
        int tirada = Dado.getInstance().tirar();
        int posicionNueva = tablero.nuevaPosicion(posicionActual, tirada);
        Casilla casilla = tablero.getCasilla(posicionNueva);
        contabilizarPasosPorSalida(jugadorActual);
        jugadorActual.moverACasilla(posicionNueva);
        casilla.recibeJugador(indiceJugadorActual, jugadores);
        contabilizarPasosPorSalida(jugadorActual);
    }
    
    public Boolean cancelarHipoteca(int ip){
        Boolean resultado = jugadores.get(indiceJugadorActual).cancelarHipoteca(ip);
        return resultado;
    }
    
    public CivitasJuego(ArrayList<String> nombres){
        jugadores = new ArrayList<>();
        for (int i = 0; i < nombres.size(); i++){
            Jugador jugador = new Jugador(nombres.get(i));
            jugadores.add(jugador);
        }
        
        gestorEstados = new GestorEstados();
        estado = gestorEstados.estadoInicial();
        
        indiceJugadorActual = Dado.getInstance().quienEmpieza(jugadores.size());
        
        mazo = new MazoSorpresas();
        
        inicializarTablero(mazo);
        
        inicializarMazoSorpresas(tablero);
    }
    
    public Boolean comprar(){
        Jugador jugadorActual = jugadores.get(indiceJugadorActual);
        int numCasillaActual = jugadorActual.getNumCasillaActual();
        Casilla casilla = tablero.getCasilla(numCasillaActual);
        TituloPropiedad titulo = casilla.getTituloPropiedad();
        Boolean res = jugadorActual.comprar(titulo);
        return res;
    }
    
    public Boolean construirCasa(int ip){
        Boolean resultado = jugadores.get(indiceJugadorActual).construirCasa(ip);
        return resultado;
    }
    
    public Boolean construirHotel(int ip){
        Boolean resultado = jugadores.get(indiceJugadorActual).construirHotel(ip);
        return resultado;
    }
    
    private void contabilizarPasosPorSalida(Jugador jugadorActual){
        if (tablero.getPorSalida() > 0){
            jugadorActual.pasaPorSalida();
        }
    }
    
    public Boolean finalDelJuego(){
        Boolean resultado = false;
        for (int i = 0; i < jugadores.size(); i++){
            if (jugadores.get(i).enBancarrota()){
                resultado = true;
            }
        }
        return resultado;
    }
    
    public Casilla getCasillaActual(){
        return tablero.getCasilla(jugadores.get(indiceJugadorActual).getNumCasillaActual());
    }
    
    public Jugador getJugadorActual(){
        return jugadores.get(indiceJugadorActual);
    }
    
    public Boolean hipotecar(int ip){
        Boolean resultado = jugadores.get(indiceJugadorActual).hipotecar(ip);
        return resultado;
    }
    
    public String infoJugadortexto(){
        return jugadores.get(indiceJugadorActual).toString();
    }
    
    private void inicializarMazoSorpresas(Tablero tablero){
        mazo.alMazo(new Sorpresa(TipoSorpresa.IRCARCEL, tablero));
        mazo.alMazo(new Sorpresa(TipoSorpresa.IRCASILLA, tablero, 18, "Debes ir a la casilla 18"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.IRCASILLA, tablero, 2, "Debes ir a la casilla 2"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.SALIRCARCEL, mazo));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR, 200, "Has ganado el concurso de belleza, ganas 200 euros"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PAGARCOBRAR, -100, "Exceso de velocidad, pagas 100 euros de multa"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PORCASAHOTEL, 100, "Ganas 100 euros por cada casa u hotel"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PORCASAHOTEL, -50, "Pagas 50 euros por cada casa u hotel"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PORJUGADOR, 100, "Cada jugador te dona 100 euros"));
        mazo.alMazo(new Sorpresa(TipoSorpresa.PORJUGADOR, -50, "Debes pagar 50 euros a cada jugador"));
    }
    
    private void inicializarTablero(MazoSorpresas mazo){
        tablero = new Tablero(5);
        //casilla 0 es la de salida
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 1", 50, 10, 150, 500, 250))); //casilla 1
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 2", 52, 10, 200, 525, 275))); //casilla 2
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa")); //casilla 3
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 4", 55, 11, 300, 550, 300))); //casilla 4
        //casilla 5 es la de carcel
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 6", 60, 12, 400, 600, 350))); //casilla 6
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 7", 65, 13, 450, 650, 400))); //casilla 7
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa")); //casilla 8
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 9", 70, 14, 500, 700, 450))); //casilla 9
        tablero.añadeCasilla(new Casilla("Descanso")); //casilla 10
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 11", 75, 15, 600, 750, 500))); //casilla 11
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 12", 80, 16, 650, 800, 550))); //casilla 12
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 13", 85, 17, 700, 850, 600))); //casilla 13
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa")); //casilla 14
        //tablero.añadeCasilla(new Casilla(tablero.getCarcel(), "Juez")); //casilla 15 es la del juez
        tablero.añadeJuez(); //casilla 15 es la del juez
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 16", 90, 18, 800, 900, 650))); //casilla 16
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 17", 95, 19, 900, 950, 700))); //casilla 17
        tablero.añadeCasilla(new Casilla(200, "Impuesto")); //casilla 18
        tablero.añadeCasilla(new Casilla(new TituloPropiedad("Calle 19", 100, 20, 1000, 750, 1000))); //casilla 19
    }
    
    private void pasarTurno(){
        indiceJugadorActual = (indiceJugadorActual + 1)% 4;
    }
    
    /*private*/ public ArrayList<Jugador> ranking(){
        ArrayList<Jugador> aux = jugadores;
        Collections.sort(aux);
        return aux;
    }
    
    public Boolean salirCarcelPagando(){
        Boolean resultado = jugadores.get(indiceJugadorActual).salirCarcelPagando();
        return resultado;
    }
    
    public Boolean salirCarcelTirando(){
        Boolean resultado = jugadores.get(indiceJugadorActual).salirCarcelTirando();
        return resultado;
    }
    
    public OperacionesJuego siguientePaso(){
        Jugador jugadorActual = jugadores.get(indiceJugadorActual);
        OperacionesJuego operacion = gestorEstados.operacionesPermitidas(jugadorActual, estado);
        if (operacion == OperacionesJuego.PASAR_TURNO){
            pasarTurno();
            siguientePasoCompletado(operacion);
        } else if (operacion == OperacionesJuego.AVANZAR){
            avanzaJugador();
            siguientePasoCompletado(operacion);
        }
        return operacion;
    }
    
    public void siguientePasoCompletado(OperacionesJuego operacion){
        estado = gestorEstados.siguienteEstado(jugadores.get(indiceJugadorActual), estado, operacion);
    }
    
    public Boolean vender(int ip){
        Boolean resultado = jugadores.get(indiceJugadorActual).vender(ip);
        return resultado;
    }
       
}
