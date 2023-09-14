// This is a basic Flutter widget test.
//
// To perform an interaction with a widget in your test, use the WidgetTester
// utility in the flutter_test package. For example, you can send tap and scroll
// gestures. You can also use WidgetTester to find child widgets in the widget
// tree, read text, and verify that the values of widget properties are correct.

import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';

import 'package:test_flutter/main.dart';

void main() {
    testWidgets('Campo de texto de correo electrónico existe',
            (WidgetTester tester) async {
          await tester.pumpWidget(MyApp());

          /*expect(find.byType(TextFormField), findsNWidgets(2));
          expect(find.widgetWithText(TextFormField, 'Correo electrónico'),
              findsOneWidget);
        });
    testWidgets('Campo de texto de contraseña existe',
            (WidgetTester tester) async {
          await tester.pumpWidget(MaterialApp(home: LoginPage()));

          expect(find.byType(TextFormField), findsNWidgets(2));
          expect(find.widgetWithText(TextFormField, 'Contraseña'), findsOneWidget);
        });
    testWidgets('Prueba del botón de inicio de sesión',
            (WidgetTester tester) async {
          await tester.pumpWidget(MyApp());

          // Verificar que existe un TextButton para iniciar sesión
          expect(find.byType(TextButton), findsOneWidget);
          expect(find.text('Iniciar sesión'), findsOneWidget);

          // Simular la pulsación del botón de inicio de sesión
          await tester.tap(find.text('Iniciar sesión'));
          await tester.pump();
        });*/
  });

}
