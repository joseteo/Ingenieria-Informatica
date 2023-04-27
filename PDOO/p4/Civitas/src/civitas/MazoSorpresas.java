
package civitas;
import java.util.ArrayList;
import java.util.Collections;


public class MazoSorpresas {
    
    private Boolean barajada;
    private Boolean debug;
    private Sorpresa ultimaSorpresa;
    private int usadas;
    
    private ArrayList<Sorpresa> sorpresas;
    private ArrayList<Sorpresa> cartasEspeciales;
    
    
    void alMazo(Sorpresa sorpresa){
        if (barajada == false){
            sorpresas.add(sorpresa);
        }
    }
    
    Sorpresa getUltimaSorpresa(){
        return ultimaSorpresa;
    }
    
    void habilitarCartaEspecial(Sorpresa sorpresa){
        Boolean encontrada = false;
        for (int i = 0; i < cartasEspeciales.size() && !encontrada; i++){
            if (cartasEspeciales.get(i) == sorpresa){
                encontrada = true;
                cartasEspeciales.remove(i);
                sorpresas.add(sorpresa);
                Diario.getInstance().ocurreEvento("carta especial habilitada");
            }
        }
    }
    
    void inhabilitarCartaEspecial(Sorpresa sorpresa){
        Boolean encontrada = false;
        for (int i = 0; i < sorpresas.size() && !encontrada; i++){
            if (sorpresas.get(i) == sorpresa){
                encontrada = true;
                sorpresas.remove(i);
                cartasEspeciales.add(sorpresa);
                Diario.getInstance().ocurreEvento("carta especial inhabilitada");
            }
        }
    }
    
    private void init(){
        sorpresas = new ArrayList<>();
        cartasEspeciales = new ArrayList<>();
        barajada = false;
        usadas = 0;
    }
    
    MazoSorpresas(Boolean debug){
        this.debug = debug;
        init();
        if (debug == true){
            Diario.getInstance().ocurreEvento("MazoSorpresas debug true");
        }
    }
    
    MazoSorpresas(){
        init();
        debug = false;
    }
    
    Sorpresa siguiente(){
        if (barajada == false || usadas == sorpresas.size()){
            if (debug == false){
                Collections.shuffle(sorpresas);
                usadas = 0;
                barajada = true;
            }
        }
        usadas++;
        ultimaSorpresa = sorpresas.get(0);
        sorpresas.remove(0);
        sorpresas.add(ultimaSorpresa);
        
        return ultimaSorpresa;
    }
        
}
