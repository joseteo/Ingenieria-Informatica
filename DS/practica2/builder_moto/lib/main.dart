import 'dart:async';

import 'package:flutter/material.dart';
import 'package:test_flutter/Asiento.dart';
import 'package:test_flutter/Builder.dart';
import 'package:test_flutter/Chasis.dart';
import 'package:test_flutter/Director.dart';
import 'package:test_flutter/Electronica.dart';
import 'package:test_flutter/Moto.dart';
import 'package:test_flutter/MotoBuilder.dart';
import 'package:test_flutter/Motor.dart';
import 'package:test_flutter/TipoFrenos.dart';
import 'package:test_flutter/TipoMoto.dart';
import 'package:test_flutter/TipoSuspension.dart';
import 'package:test_flutter/TrenRodaje.dart';

void main() {
  runApp(MotoBuilderApp());
}

class MotoBuilderApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        useMaterial3: true,
        colorSchemeSeed: Colors.blue,
      ),
      home: const PopupMenuEjemplo(),
    );
  }
}

class PopupMenuEjemplo extends StatefulWidget {
  const PopupMenuEjemplo({super.key});

  @override
  // ignore: library_private_types_in_public_api
  _MyHomePageState createState() => _MyHomePageState();
}

TipoMoto? selectedMoto;
int? selectedPulgada;
TipoFrenos? selectedFrenos;
TipoSuspension? selectedSuspension;
Asiento? selectedAsiento;
Motor? selectedMotor;
Electronica selectedElectronica = Electronica(false, false, false, false);
bool _visible = false;

class _MyHomePageState extends State<PopupMenuEjemplo> {
  final MotoBuilder builder = MotoBuilder(
      TipoMoto.MOTODEPORTIVA,
      Chasis.MONOCASCO,
      Asiento.ASIENTOROJO,
      Motor(TipoMoto.MOTODEPORTIVA),
      TrenRodaje(17, TipoFrenos.DISCO, TipoSuspension.DURA),
      Electronica(true, false, true, true));
  late Moto moto = builder.entregaMoto();

  @override
  void initState() {
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('MOTO BUILDER'),
        titleTextStyle: const TextStyle(
          color: Colors.white,
          fontSize: 40,
          fontWeight: FontWeight.bold,
        ),
        bottom: PreferredSize(
            child: Container(
              color: Colors.red,
            ),
            preferredSize: const Size.fromHeight(10.0)),
        centerTitle: true,
        backgroundColor: Colors.red,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            const Text(
              'Configura tu moto',
              style: TextStyle(fontSize: 24.0),
            ),
            const SizedBox(height: 10.0),
            Container(
              width: 250,
              height: 55,
              decoration: const ShapeDecoration(
                color: Colors.white,
                shape: StadiumBorder(
                  side: BorderSide(color: Colors.black, width: 2),
                ),
              ),
              child: Theme(
                data: ThemeData(
                  popupMenuTheme: const PopupMenuThemeData(
                      color: Colors
                          .transparent // Aquí se cambia el color de fondo del menú emergente
                      ),
                ),
                child: PopupMenuButton<TipoMoto>(
                  // ignore: sort_child_properties_last
                  child: Row(
                    children: [
                      const SizedBox(width: 30.0),
                      const Text('Tipo de Moto'),
                      const SizedBox(width: 45.0),
                      Image.asset(
                        'assets/images/MotoDeportiva.png',
                        height: 50,
                        width: 50,
                        fit: BoxFit.fitWidth,
                      ),
                      const SizedBox(width: 8.0),
                    ],
                  ),
                  initialValue: selectedMoto,
                  onSelected: (TipoMoto item) {
                    setState(() {
                      selectedMoto = item;
                      selectedMotor = Motor(item);
                      moto.tipoMoto = selectedMoto!;
                    });
                  },

                  itemBuilder: (BuildContext context) =>
                      <PopupMenuEntry<TipoMoto>>[
                    PopupMenuItem<TipoMoto>(
                      value: TipoMoto.MOTODEPORTIVA,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(30.0),
                              topRight: Radius.circular(30.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            const Text('Moto Deportiva'),
                            const SizedBox(width: 18.0),
                            Image.asset(
                              'assets/images/MotoDeportiva.png',
                              height: 40,
                              width: 40,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    PopupMenuItem<TipoMoto>(
                      value: TipoMoto.MOTOSCOOTER,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Moto Scooter'),
                            const SizedBox(width: 30.0),
                            Image.asset(
                              'assets/images/MotoScooter.png',
                              height: 40,
                              width: 40,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    PopupMenuItem<TipoMoto>(
                      value: TipoMoto.MOTOTOURING,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(30.0),
                              bottomRight: Radius.circular(30.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Moto Touring'),
                            const SizedBox(width: 30.0),
                            Image.asset(
                              'assets/images/MotoTouring2.png',
                              height: 50,
                              width: 50,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
            const SizedBox(height: 10.0),
            Container(
              width: 250,
              height: 55,
              decoration: const ShapeDecoration(
                color: Colors.white,
                shape: StadiumBorder(
                  side: BorderSide(color: Colors.black, width: 2),
                ),
              ),
              child: Theme(
                data: ThemeData(
                  popupMenuTheme: const PopupMenuThemeData(
                      color: Colors
                          .transparent // Aquí se cambia el color de fondo del menú emergente
                      ),
                ),
                child: PopupMenuButton<int>(
                  // ignore: sort_child_properties_last
                  child: Row(
                    children: [
                      const SizedBox(width: 30.0),
                      const Text('Tamaño Ruedas'),
                      const SizedBox(width: 28.0),
                      Image.asset(
                        'assets/images/Rueda.png',
                        height: 50,
                        width: 50,
                        fit: BoxFit.fitWidth,
                      ),
                      const SizedBox(width: 8.0),
                    ],
                  ),
                  initialValue: selectedPulgada,
                  onSelected: (int item) {
                    setState(() {
                      selectedPulgada = item;
                      moto.trenRodaje.pulgadaRueda = selectedPulgada!;
                    });
                  },

                  itemBuilder: (BuildContext context) => <PopupMenuEntry<int>>[
                    PopupMenuItem<int>(
                      value: 14,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(30.0),
                              topRight: Radius.circular(30.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            const Text('14 Pulgadas'),
                            const SizedBox(width: 18.0),
                            Image.asset(
                              'assets/images/Rueda.png',
                              height: 38,
                              width: 38,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    PopupMenuItem<int>(
                      value: 15,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            const Text('15 Pulgadas'),
                            const SizedBox(width: 12.0),
                            Image.asset(
                              'assets/images/Rueda.png',
                              height: 45,
                              width: 45,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    PopupMenuItem<int>(
                      value: 16,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(30.0),
                              bottomRight: Radius.circular(30.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            const Text('16 Pulgadas'),
                            const SizedBox(width: 8.0),
                            Image.asset(
                              'assets/images/Rueda.png',
                              height: 50,
                              width: 50,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
            const SizedBox(height: 10.0),
            Container(
              width: 250,
              height: 55,
              decoration: const ShapeDecoration(
                color: Colors.white,
                shape: StadiumBorder(
                  side: BorderSide(color: Colors.black, width: 2),
                ),
              ),
              child: Theme(
                data: ThemeData(
                  popupMenuTheme: const PopupMenuThemeData(
                      color: Colors
                          .transparent // Aquí se cambia el color de fondo del menú emergente
                      ),
                ),
                child: PopupMenuButton<TipoFrenos>(
                  // ignore: prefer_const_constructors, sort_child_properties_last
                  child: Row(
                    children: [
                      const SizedBox(width: 30.0),
                      const Text('Tipo de Frenos'),
                      const SizedBox(
                        width: 38.0,
                      ),
                      Image.asset(
                        'assets/images/TipoFrenos.png',
                        height: 45,
                        width: 45,
                      ),
                      const SizedBox(width: 8.0),
                    ],
                  ),
                  initialValue: selectedFrenos,
                  onSelected: (TipoFrenos item) {
                    setState(() {
                      selectedFrenos = item;
                      moto.trenRodaje.tipoFrenos = selectedFrenos!;
                    });
                  },
                  itemBuilder: (BuildContext context) =>
                      <PopupMenuEntry<TipoFrenos>>[
                    // ignore: prefer_const_constructors
                    PopupMenuItem<TipoFrenos>(
                      value: TipoFrenos.DISCO,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(30.0),
                              topRight: Radius.circular(30.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Frenos Disco'),
                            const SizedBox(width: 32.0),
                            Image.asset(
                              'assets/images/TipoFrenos.png',
                              height: 35,
                              width: 35,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    // ignore: prefer_const_constructors
                    PopupMenuItem<TipoFrenos>(
                      value: TipoFrenos.TAMBOR,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(30.0),
                              bottomRight: Radius.circular(30.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Frenos Tambor'),
                            const SizedBox(width: 20.0),
                            Image.asset(
                              'assets/images/FrenoTambor.png',
                              height: 35,
                              width: 35,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
            const SizedBox(height: 10.0),
            Container(
              width: 250,
              height: 55,
              decoration: const ShapeDecoration(
                color: Colors.white,
                shape: StadiumBorder(
                  side: BorderSide(color: Colors.black, width: 2),
                ),
              ),
              child: Theme(
                data: ThemeData(
                  popupMenuTheme: const PopupMenuThemeData(
                      color: Colors
                          .transparent // Aquí se cambia el color de fondo del menú emergente
                      ),
                ),
                child: PopupMenuButton<TipoSuspension>(
                  //SizedBox(width: 20, height: 10),
                  // ignore: prefer_const_constructors, sort_child_properties_last
                  child: Row(
                    children: [
                      const SizedBox(width: 30.0),
                      const Text('Tipo de Suspension'),
                      const SizedBox(
                        width: 7.0,
                      ),
                      Image.asset(
                        'assets/images/Suspension.png',
                        height: 45,
                        width: 45,
                      ),
                    ],
                  ),
                  initialValue: selectedSuspension,
                  onSelected: (TipoSuspension item) {
                    setState(() {
                      selectedSuspension = item;
                      moto.trenRodaje.tipoSuspension = selectedSuspension!;
                    });
                  },

                  itemBuilder: (BuildContext context) =>
                      <PopupMenuEntry<TipoSuspension>>[
                    // ignore: prefer_const_constructors

                    PopupMenuItem<TipoSuspension>(
                      value: TipoSuspension.DURA,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(30.0),
                              topRight: Radius.circular(30.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Dura'),
                            const SizedBox(width: 32.0),
                            Image.asset(
                              'assets/images/Suspension.png',
                              height: 35,
                              width: 35,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    // ignore: prefer_const_constructors
                    PopupMenuItem<TipoSuspension>(
                      value: TipoSuspension.MEDIA,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Media'),
                            const SizedBox(width: 32.0),
                            Image.asset(
                              'assets/images/Suspension.png',
                              height: 35,
                              width: 35,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    PopupMenuItem<TipoSuspension>(
                      value: TipoSuspension.BLANDA,
                      textStyle: const TextStyle(color: Colors.black),
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(30.0),
                              bottomRight: Radius.circular(30.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Blanda'),
                            const SizedBox(width: 30.0),
                            Image.asset(
                              'assets/images/Suspension.png',
                              height: 35,
                              width: 35,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                  //position: RelativeRect.fromLTRB(0, 0, 0, 0),
                  //offset: Offset(20, -2),
                ),
              ),
            ),
            const SizedBox(height: 10.0),
            Container(
              width: 250,
              height: 55,
              decoration: const ShapeDecoration(
                color: Colors.white,
                shape: StadiumBorder(
                  side: BorderSide(color: Colors.black, width: 2),
                ),
              ),
              child: Theme(
                data: ThemeData(
                  popupMenuTheme: const PopupMenuThemeData(
                      color: Colors
                          .transparent // Aquí se cambia el color de fondo del menú emergente
                      ),
                ),
                child: PopupMenuButton<Asiento>(
                  // ignore: prefer_const_constructors, sort_child_properties_last
                  child: Row(
                    children: [
                      const SizedBox(width: 30.0),
                      const Text('Color de Asiento'),
                      const SizedBox(
                        width: 30.0,
                      ),
                      Image.asset(
                        'assets/images/AsientoBlanco.png',
                        height: 45,
                        width: 45,
                      ),
                      const SizedBox(width: 8.0),
                    ],
                  ),
                  initialValue: selectedAsiento,
                  onSelected: (Asiento item) {
                    setState(() {
                      selectedAsiento = item;
                      moto.asiento = selectedAsiento!;
                    });
                  },
                  itemBuilder: (BuildContext context) =>
                      <PopupMenuEntry<Asiento>>[
                    // ignore: prefer_const_constructors
                    PopupMenuItem<Asiento>(
                      value: Asiento.ASIENTOBLANCO,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(30.0),
                              topRight: Radius.circular(30.0),
                              bottomLeft: Radius.circular(0.0),
                              bottomRight: Radius.circular(0.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Asiento Blanco'),
                            const SizedBox(width: 32.0),
                            Image.asset(
                              'assets/images/AsientoBlanco.png',
                              height: 40,
                              width: 40,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                    // ignore: prefer_const_constructors
                    PopupMenuItem<Asiento>(
                      value: Asiento.ASIENTOROJO,
                      child: Container(
                        width: 250,
                        height: 55,
                        decoration: BoxDecoration(
                          color: Colors.white,
                          border: Border.all(
                            color: Colors.black,
                            width: 2,
                          ),
                          borderRadius: const BorderRadius.only(
                              topLeft: Radius.circular(0.0),
                              topRight: Radius.circular(0.0),
                              bottomLeft: Radius.circular(30.0),
                              bottomRight: Radius.circular(30.0)),
                        ),
                        child: Row(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: [
                            const Text('Asiento Rojo'),
                            const SizedBox(width: 45.0),
                            Image.asset(
                              'assets/images/AsientoRojo.png',
                              height: 40,
                              width: 40,
                              fit: BoxFit.fitWidth,
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),
            const SizedBox(height: 10.0),
            Container(
              width: 250,
              height: 250,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: Center(
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Row(
                      children: [
                        const SizedBox(width: 15.0),
                        const Text('Electronica'),
                        const SizedBox(width: 20.0),
                        Image.asset(
                          'assets/images/Electronica.png',
                          height: 50,
                          width: 50,
                        ),
                      ],
                    ),
                    const SizedBox(
                      height: 1.0,
                    ),
                    Row(
                      children: [
                        Checkbox(
                          checkColor: Colors.white,
                          value: selectedElectronica.abs,
                          onChanged: (bool? value) {
                            setState(() {
                              selectedElectronica.abs = value!;
                              moto.electronica.abs = selectedElectronica.abs;
                            });
                          },
                        ),
                        const Text('ABS '),
                        const SizedBox(width: 106.0),
                        Image.asset(
                          'assets/images/ABS.png',
                          height: 35,
                          width: 35,
                          fit: BoxFit.fitWidth,
                        ),
                      ],
                    ),
                    Row(
                      children: [
                        Checkbox(
                          checkColor: Colors.white,
                          value: selectedElectronica.controlCrucero,
                          onChanged: (bool? value) {
                            setState(() {
                              selectedElectronica.controlCrucero = value!;
                              moto.electronica.controlCrucero =
                                  selectedElectronica.controlCrucero;
                            });
                          },
                        ),
                        const Text('Control de Crucero'),
                        const SizedBox(width: 16.0),
                        Image.asset(
                          'assets/images/ControlCrucero.png',
                          height: 35,
                          width: 35,
                          fit: BoxFit.fitWidth,
                        ),
                      ],
                    ),
                    Row(
                      children: [
                        Checkbox(
                          checkColor: Colors.white,
                          value: selectedElectronica.controlTraccion,
                          onChanged: (bool? value) {
                            setState(() {
                              selectedElectronica.controlTraccion = value!;
                              moto.electronica.controlTraccion =
                                  selectedElectronica.controlTraccion;
                            });
                          },
                        ),
                        const Text('Control de Traccion'),
                        const SizedBox(width: 13.0),
                        Image.asset(
                          'assets/images/ControlTraccion.png',
                          height: 32,
                          width: 32,
                          fit: BoxFit.fitWidth,
                        ),
                      ],
                    ),
                    Row(
                      children: [
                        Checkbox(
                          checkColor: Colors.white,
                          value: selectedElectronica.repartoFrenada,
                          onChanged: (bool? value) {
                            setState(() {
                              selectedElectronica.repartoFrenada = value!;
                              moto.electronica.repartoFrenada =
                                  selectedElectronica.repartoFrenada;
                            });
                          },
                        ),
                        const Text('Reparto de Frenada'),
                        const SizedBox(width: 11.0),
                        Image.asset(
                          'assets/images/EBD.png',
                          height: 35,
                          width: 35,
                          fit: BoxFit.fitWidth,
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
            const SizedBox(height: 10.0),
            Container(
              width: 300,
              height: 100,
              child: Center(
                child: ElevatedButton(
                  style: ButtonStyle(
                      foregroundColor: MaterialStateProperty.all(Colors.black),
                      backgroundColor: MaterialStateProperty.all(Colors.red)),
                  child: Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        const SizedBox(width: 10.0),
                        const Text('Finalizar',
                            style:
                                TextStyle(color: Colors.white, fontSize: 20.0)),
                      ]),
                  onPressed: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                          builder: (context) => SegundaPantalla()),
                    );
                  },
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

/*************************************************************
************* PRUEBA APARICION BOTON CONFIGURACION ***********
***************************************************************/
class SegundaPantalla extends StatefulWidget {
  SegundaPantalla({Key? key}) : super(key: key);

  @override
  _SegundaPantallaState createState() => _SegundaPantallaState();
}

class _SegundaPantallaState extends State<SegundaPantalla> {
  bool _EsvisibleBotonConf = false;
  bool _EsvisibleCompleted = false;
  bool _Novisible = true;

  @override
  void initState() {
    super.initState();
    Timer(Duration(seconds: 7), () {
      setState(() {
        _EsvisibleBotonConf = true;
      });
    });
    Timer(Duration(seconds: 6), () {
      setState(() {
        _EsvisibleCompleted = true;
        _Novisible = false;
      });
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Cargando su configuración'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Visibility(
              visible: _Novisible,
              child: Image.asset(
                'assets/images/LoadingMoto3.gif',
                height: 250,
                width: 250,
                fit: BoxFit.fitWidth,
              ),
            ),
            Visibility(
              visible: _EsvisibleCompleted,
              child: Image.asset(
                'assets/images/Completed.gif',
                height: 500,
                width: 500,
                fit: BoxFit.fitWidth,
              ),
            ),
            SizedBox(height: 16.0),
            Visibility(
              visible: _EsvisibleBotonConf,
              child: ElevatedButton(
                child: Text('Ir a su Configuración'),
                onPressed: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(builder: (context) => TerceraPantalla()),
                  );
                },
              ),
            ),
            SizedBox(width: 16.0),
            Visibility(
              visible: _Novisible,
              child: ElevatedButton(
                child: Text('Volver a su Configuración'),
                onPressed: () {
                  Navigator.pop(context);
                },
              ),
            ),
          ],
        ),
      ),
    );
  }
}

/*
TERCERA PANTALLA
*/

class TerceraPantalla extends StatefulWidget {
  TerceraPantalla({Key? key}) : super(key: key);

  @override
  _TerceraPantallaState createState() => _TerceraPantallaState();
}

class _TerceraPantallaState extends State<TerceraPantalla> {
  bool shouldPop = false;
  @override
  Widget build(BuildContext context) {
    return WillPopScope(
      onWillPop: () async {
        return shouldPop;
      },
      child: Scaffold(
        appBar: AppBar(
          title: const Text('Motillo fiaumm'),
        ),
        body: Center(
          child: Column(mainAxisAlignment: MainAxisAlignment.start, children: [
            const SizedBox(height: 24.0),
            Container(
              width: 250,
              height: 55,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      "Tipo de moto: ${selectedMoto?.toShortString()}",
                      style: const TextStyle(fontSize: 18.0),
                    ),
                  ]),
            ),
            const SizedBox(height: 8.0),
            Container(
              width: 250,
              height: 55,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      "Suspensión: ${selectedSuspension?.toShortString()}",
                      style: const TextStyle(fontSize: 18.0),
                    ),
                  ]),
            ),
            const SizedBox(height: 8.0),
            Container(
              width: 250,
              height: 55,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      'Frenos: ${selectedFrenos?.toShortString()}',
                      style: const TextStyle(fontSize: 18.0),
                    ),
                  ]),
            ),
            const SizedBox(height: 8.0),
            Container(
              width: 250,
              height: 120,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: FittedBox(
                fit: BoxFit.scaleDown,
                child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text(
                        'Motor: ${selectedMotor.toString()}',
                        style: const TextStyle(fontSize: 18.0),
                      ),
                    ]),
              ),
            ),
            const SizedBox(height: 8.0),
            Container(
              width: 250,
              height: 120,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: FittedBox(
                fit: BoxFit.scaleDown,
                child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text(
                        'Electrónica: ${selectedElectronica.toString()}',
                        style: const TextStyle(fontSize: 18.0),
                      ),
                    ]),
              ),
            ),
            const SizedBox(height: 8.0),
            Container(
              width: 250,
              height: 55,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      'Asiento: ${selectedAsiento?.toShortString()}',
                      style: const TextStyle(fontSize: 18.0),
                    ),
                  ]),
            ),
            const SizedBox(height: 8.0),
            Container(
              width: 250,
              height: 55,
              decoration: BoxDecoration(
                color: Colors.white,
                border: Border.all(
                  color: Colors.black,
                  width: 2,
                ),
                borderRadius: const BorderRadius.only(
                    topLeft: Radius.circular(30.0),
                    topRight: Radius.circular(30.0),
                    bottomLeft: Radius.circular(30.0),
                    bottomRight: Radius.circular(30.0)),
              ),
              child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Text(
                      'Tamaño Ruedas: ${selectedPulgada.toString()} in.',
                      style: const TextStyle(fontSize: 18.0),
                    ),
                  ]),
            ),
            const SizedBox(height: 24.0),
            Container(
              width: 300,
              height: 50,
              child: ElevatedButton(
                style: ButtonStyle(
                    foregroundColor: MaterialStateProperty.all(Colors.black),
                    backgroundColor: MaterialStateProperty.all(Colors.red)),
                child:
                    Row(mainAxisAlignment: MainAxisAlignment.center, children: [
                  const SizedBox(width: 10.0),
                  const Text('Nueva Configuración.',
                      style: TextStyle(color: Colors.white, fontSize: 20.0)),
                ]),
                onPressed: () {
                  Navigator.popUntil(context, (route) => route.isFirst);
                },
              ),
            ),
          ]),
        ),
      ),
    );
  }
}

/*
const SizedBox(height: 8.0),
            Text(
              "Suspensión: ${selectedSuspension?.toShortString()}",
              style: const TextStyle(fontSize: 18.0),
            ),
            const SizedBox(height: 8.0),
            Text(
              'Frenos: ${selectedFrenos?.toShortString()}',
              style: const TextStyle(fontSize: 18.0),
            ),
            const SizedBox(height: 8.0),
            Text(
              'Motor: ${selectedMotor.toString()}',
              style: const TextStyle(fontSize: 18.0),
            ),
            const SizedBox(height: 8.0),
            Text(
              'Electrónica: ${selectedElectronica.toString()}',
              style: const TextStyle(fontSize: 18.0),
            ),
            const SizedBox(height: 8.0),
            Text(
              'Asiento: ${selectedAsiento?.toShortString()}',
              style: const TextStyle(fontSize: 18.0),
            ),
            const SizedBox(height: 8.0),
            Text(
              'Pulgadas Ruedas: ${selectedPulgada.toString()}',
              style: const TextStyle(fontSize: 18.0),
            ),
            const SizedBox(height: 24.0),
            ElevatedButton(
              child: const Text('Nueva Configuración.'),
              onPressed: () {
                Navigator.popUntil(context, (route) => route.isFirst);
              },
            ),
 */

/*

**************** NAVEGACION ENTRE PAGINAS EJEMPLO ********************

import 'package:flutter/material.dart';

void main() {
  runApp(const MaterialApp(
    title: 'Navigation Basics',
    home: FirstRoute(),
  ));
}

class FirstRoute extends StatelessWidget {
  const FirstRoute({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('First Route'),
      ),
      body: Center(
        child: ElevatedButton(
          child: const Text('Open route'),
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(builder: (context) => const SecondRoute()),
            );
          },
        ),
      ),
    );
  }
}

class SecondRoute extends StatelessWidget {
  const SecondRoute({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Second Route'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            ElevatedButton(
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => const ThirdRoute()),
                );
              },
              child: const Text('Open second rute'),
            ),
            SizedBox(height: 10.0),
            ElevatedButton(
              child: Text('Atras'),
              onPressed: () {
                Navigator.pop(context);
              },
            ),
          ],
        ),
      ),
    );
  }
}

class ThirdRoute extends StatelessWidget {
  const ThirdRoute({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Third Route'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            ElevatedButton(
              child: Text('Volver Atras'),
              onPressed: () {
                Navigator.pop(context);
              },
            ),
            SizedBox(height: 10.0),
            ElevatedButton(
              child: Text('Volver al Inicio'),
              onPressed: () {
                Navigator.popUntil(
                  context, 
                  (route) => route.isFirst);
              },
            ),
          ],
        ),
      ),
    );
  }
}


*/

/*
          const SizedBox(height: 24.0),
          Text(
            "Tipo de moto: ${selectedMoto.toShortString()}",
            style: const TextStyle(fontSize: 18.0),
          ),
          const SizedBox(height: 8.0),
          Text(
            'Chasis: ${selectedChasis.toShortString()}',
            style: const TextStyle(fontSize: 18.0),
          ),
          const SizedBox(height: 8.0),
          Text(
            'Suspensión: ${selectedSuspension.toString()}',
            style: const TextStyle(fontSize: 18.0),
          ),
          const SizedBox(height: 8.0),
          Text(
            'Frenos: ${selectedFrenos.toString()}',
            style: const TextStyle(fontSize: 18.0),
          ),
          const SizedBox(height: 8.0),
          Text(
            'Motor: ${selectedMotor.toString()}',
            style: const TextStyle(fontSize: 18.0),
          ),
          const SizedBox(height: 8.0),
          Text(
            'Electrónica: ${selectedElectronica.toString()}',
            style: const TextStyle(fontSize: 18.0),
          ),
          const SizedBox(height: 8.0),
          Text(
            'Asiento: ${selectedAsiento.toString()}',
            style: const TextStyle(fontSize: 18.0),
          ),
          Text(
            'Pulgadas Ruedas: ${moto.trenRodaje.pulgadaRueda}',
            style: const TextStyle(fontSize: 18.0),
          ),
          const SizedBox(height: 24.0),
          ElevatedButton(
            onPressed: () {
              setState(() {
                print("Has creado tu moto");
              });
            },
            child: const Text('Crear otra moto'),
          ),*/
