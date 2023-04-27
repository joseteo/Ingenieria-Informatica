
package civitas;

import java.util.ArrayList;


public class SalirCarcelSorpresa extends Sorpresa{
    
    private final String salircarcel= "salircarcel";
    private MazoSorpresas mazo;
    
    SalirCarcelSorpresa(MazoSorpresas mazo){
        //Para construir la sorpresa que permite evitar la carcel
        this.mazo = mazo;
        super.texto = "Quedas libre de la carcel";
    }
     
    @Override
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            //informe(actual, todos);
            Boolean poseido = false;
            for (int i = 0; i < todos.size(); i++){
                if (todos.get(i).tieneSalvoconducto() == true){
                    poseido = true;
                }
            }
            if (!poseido){
                todos.get(actual).obtenerSalvoconducto(this);
                salirDelMazo();
            }
        }
    }
    
    public String salircarcel(){
        return salircarcel;
    }
    
    @Override public Boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos){
        Boolean resultado = false;
        if (actual >= 0 && actual < todos.size()){
            resultado = true;
        }
        return resultado;
    }
    
    @Override public void informe(int actual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("se esta aplicando una sorpresa al jugador " + todos.get(actual).getNombre());
    }
}
