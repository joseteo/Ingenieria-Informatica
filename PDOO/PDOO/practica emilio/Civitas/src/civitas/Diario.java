package civitas;

import java.util.ArrayList;

public class Diario {
  //Atributos de clase
  static final private Diario instance = new Diario();
  //Atributos de instancia
  private final ArrayList<String> eventos;
  
  static public Diario getInstance() {
    return instance;
  }

    public ArrayList<String> getEventos() {
        return eventos;
    }
  
  
  
  public Diario () {
    eventos = new ArrayList<>();
  }
  
  void ocurreEvento (String e) {
    eventos.add (e);
  }
  
  public boolean eventosPendientes () {
    return !eventos.isEmpty();
  }
  
  public String leerEvento () {
    String salida = "";
    if (!eventos.isEmpty()) {
      salida = eventos.remove(0);
    }
    return salida;
  }
}
