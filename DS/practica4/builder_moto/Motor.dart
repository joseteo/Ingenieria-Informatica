class Motor {
  int _cv;
  int _cc;
  int _kilometraje;
  int _inyeccion;

  Motor(
    this._cv,
    this._cc,
    this._kilometraje,
    this._inyeccion,
  );

  int get cv {
    return _cv;
  }

  int get cc {
    return _cc;
  }

  int get kilometraje {
    return _kilometraje;
  }

  int get inyeccion {
    return _inyeccion;
  }

  set cv (int cv) {
    _cv = cv;
  }

  set cc (int cc) {
    _cc = cc;
  }

  set kilometraje (int kilometraje) {
    _kilometraje = kilometraje;
  }

  set inyeccion (int inyeccion) {
    _inyeccion = inyeccion;
  }


}