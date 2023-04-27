
package civitas;
import java.util.ArrayList;


public class Tablero {
    
    private int numCasillaCarcel;  
    private int porSalida;
    private Boolean tieneJuez;
    
    private ArrayList<Casilla> casillas;
    
        
    Tablero(int indiceCarcel){
        if (indiceCarcel >= 1){
            numCasillaCarcel = indiceCarcel;
        } else {
            numCasillaCarcel = 1;
        }
        
        casillas = new ArrayList<>();
        Casilla Salida = new Casilla("Salida");
        casillas.add(Salida);
        
        porSalida = 0;
        
        tieneJuez = false;
    }
    
    private Boolean correcto(){
        Boolean resultado = false;
        if (casillas.size() > numCasillaCarcel && tieneJuez == true){
            resultado = true;            
        }
        return resultado;
    }
    
    private Boolean correcto(int numCasilla){
        Boolean resultado = false;
        if (correcto() == true && numCasilla < casillas.size()){
            resultado = true;
        }
        return resultado;
    }
    
    int getCarcel(){
        return numCasillaCarcel;
    }
    
    int getPorSalida(){
        int resultado = porSalida;
        if (porSalida > 0){
            porSalida--;
        }
        return resultado;
    }
    
    void añadeCasilla(Casilla casilla){
        if (casillas.size() == numCasillaCarcel){
            Casilla Carcel = new Casilla("Carcel");
            casillas.add(Carcel);
        }
        if (casilla instanceof CasillaJuez){
            añadeJuez();
        } else {
            casillas.add(casilla);
        }
        if (casillas.size() == numCasillaCarcel){
            Casilla Carcel = new Casilla("Carcel");
            casillas.add(Carcel);
        }
    }
    
    void añadeJuez(){
        if(tieneJuez == false){
            CasillaJuez Juez = new CasillaJuez(numCasillaCarcel,"Juez");
            casillas.add(Juez);
            tieneJuez = true;
        }
    }
    
    Casilla getCasilla(int numCasilla){
        Casilla resultado = null;
        if (correcto(numCasilla) == true){
            resultado = casillas.get(numCasilla);
        }
        return resultado;
    }
    
    int nuevaPosicion(int actual, int tirada){
        int resultado;
        if (correcto() == false){
            resultado = -1;
        } else {
            resultado = actual + tirada;
            if (correcto(resultado) == false){
                int aux = resultado - casillas.size();
                resultado = aux;
            }
        }
        if (resultado != actual+tirada){
            porSalida++;
        }
        return resultado;
    }
    
    int calcularTirada(int origen, int destino){
        int resultado;
        resultado = destino - origen;
        if (resultado < 0){
            resultado = resultado + casillas.size();
        }
        return resultado;
    }
    
}
