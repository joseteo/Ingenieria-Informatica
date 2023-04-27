enum Asiento { ASIENTOROJO, ASIENTOBLANCO }

extension ParseToString on Asiento {
  String toShortString() {
    switch (this) {
      case Asiento.ASIENTOROJO:
        return "Color Rojo";
      case Asiento.ASIENTOBLANCO:
        return "Color Blanco";
      default:
        return "Sin tipo de color";
    }
  }
}
