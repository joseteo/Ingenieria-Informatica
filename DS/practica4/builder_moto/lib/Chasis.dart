enum Chasis {
  SIMPLECUNACERRADO,
  SIMPLECUNAABIERTO,
  SIMPLECUNADESDOBLADO,
  DOBLECUNA,
  MULTITUBULAR,
  DOBLEVIGAPERIMETRAL,
  MONOCASCO,
  OMEGA
}

extension ParseToString on Chasis {
  String toShortstring() {
    switch (this) {
      case Chasis.SIMPLECUNACERRADO:
        return "Simple cuna cerrado";
      case Chasis.SIMPLECUNAABIERTO:
        return "Simple cuna abierto";
      case Chasis.SIMPLECUNADESDOBLADO:
        return "Simple cuna desdoblado";
      case Chasis.DOBLECUNA:
        return "Doblecuna";
      case Chasis.MULTITUBULAR:
        return "Multitubular";
      case Chasis.DOBLEVIGAPERIMETRAL:
        return "Doble viga perimetral";
      case Chasis.MONOCASCO:
        return "Monocasco";
      case Chasis.OMEGA:
        return "Omega";
      default:
        return "Sin tipo de chasis";
    }
  }
}
