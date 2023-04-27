
package civitas;
import java.util.ArrayList;

public class Sorpresa {
    private String texto;
    private int valor;
    
    private MazoSorpresas mazo;
    private TipoSorpresa tipo;
    private Tablero tablero;
    
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if (tipo == TipoSorpresa.IRCARCEL){
            aplicarAJugador_irCarcel(actual, todos);
        } else if (tipo == TipoSorpresa.IRCASILLA){
            aplicarAJugador_irACasilla(actual, todos);
        } else if (tipo == TipoSorpresa.PAGARCOBRAR){
            aplicarAJugador_pagarCobrar(actual, todos);
        } else if (tipo == TipoSorpresa.PORCASAHOTEL){
            aplicarAJugador_porCasaHotel(actual, todos);
        } else if (tipo == TipoSorpresa.PORJUGADOR){
            aplicarAJugador_porJugador(actual, todos);
        } else if (tipo == TipoSorpresa.SALIRCARCEL){
            aplicarAJugador_salirCarcel(actual, todos);
        }
    }
    
    private void aplicarAJugador_irACasilla(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            int casillaActual = todos.get(actual).getNumCasillaActual();
            int tirada = tablero.calcularTirada(casillaActual, valor);
            int nuevaPosicion = tablero.nuevaPosicion(casillaActual, tirada);
            todos.get(actual).moverACasilla(nuevaPosicion);
            tablero.getCasilla(valor).recibeJugador(actual, todos);
        }
    }
    
    private void aplicarAJugador_irCarcel(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            todos.get(actual).encarcelar(tablero.getCarcel());
        }
    }
    
    private void aplicarAJugador_pagarCobrar(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            todos.get(actual).modificarSaldo(valor);
        }
    }
    
    private void aplicarAJugador_porCasaHotel(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            todos.get(actual).modificarSaldo(valor * todos.get(actual).cantidadCasasHoteles());
        }
    }
    
    private void aplicarAJugador_porJugador(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            Sorpresa s1 = new Sorpresa(TipoSorpresa.PAGARCOBRAR, valor * -1, "PAGARCOBRAR");
            for (int i = 0; i < actual; i++){
                s1.aplicarAJugador(i, todos);
            }
            for (int i = actual + 1; i < todos.size(); i++){
                s1.aplicarAJugador(i, todos);
            }
            Sorpresa s2 = new Sorpresa(TipoSorpresa.PAGARCOBRAR, valor * (todos.size() - 1), "PAGARCOBRAR");
            s2.aplicarAJugador(actual, todos);
        }
    }
    
    private void aplicarAJugador_salirCarcel(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            Boolean poseido = false;
            for (int i = 0; i < todos.size(); i++){
                if (todos.get(i).tieneSalvoconducto() == true){
                    poseido = true;
                }
            }
            if (poseido = false){
                todos.get(actual).obtenerSalvoconducto(this);
                salirDelMazo();
            }
        }
    }
    
    private void informe(int actual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("se esta aplicando una sorpresa al jugador " + todos.get(actual).getNombre());
    }
    
    private void init(){
        valor = -1;
        mazo = null;
        tablero = null;
        texto = "";
    }
    
    public Boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos){
        Boolean resultado = false;
        if (actual >= 0 && actual < todos.size()){
            resultado = true;
        }
        return resultado;
    }
    
    void salirDelMazo(){
        if (tipo == TipoSorpresa.SALIRCARCEL){
            mazo.inhabilitarCartaEspecial(this);
        }
    }
    
    Sorpresa(TipoSorpresa tipo, Tablero tablero){
        //Para constuir la sorpresa que envia a la carcel
        init();
        this.tipo = tipo;
        this.tablero = tablero;
        texto = "Debes ir a la carcel";
    }
    
    Sorpresa(TipoSorpresa tipo, Tablero tablero, int valor, String texto){
        //Para constuir la sorpresa que envia al jugador a otra casilla
        init();
        this.tipo = tipo;
        this.tablero = tablero;
        this.valor = valor;
        this.texto = texto;
    }
    
    Sorpresa(TipoSorpresa tipo, int valor, String texto){
        //Para el resto de sorpresas
        init();
        this.tipo = tipo;
        this.valor = valor;
        this.texto = texto;
    }
    
    Sorpresa(TipoSorpresa tipo, MazoSorpresas mazo){
        //Para construir la sorpresa que permite evitar la carcel
        init();
        this.tipo = tipo;
        this.mazo = mazo;
        texto = "Quedas libre de la carcel";
    }
    
    @Override
    public String toString(){
        return "Sorpresa{" + "texto=" + texto + ", valor=" + Integer.toString(valor) + ", tipo=" + tipo + "}";
    }
    
    void usada(){
        if (tipo == TipoSorpresa.SALIRCARCEL){
            mazo.habilitarCartaEspecial(this);
        }
    }
}
