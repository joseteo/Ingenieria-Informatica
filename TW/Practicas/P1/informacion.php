<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Ejemplo con PHP</title>
</head>
<body>
	<h1>Usted se está conectando desde:</h1>
	<p>Dirección IP: <?php echo $_SERVER['REMOTE_ADDR'] ?? 'Sin definir';?></p>
	<p>Nombre de dominio: <?php echo $_SERVER['REMOTE_HOST'] ?? 'Sin definir';?></p>
	<p>Agente de usuario: <?php echo $_SERVER['HTTP_USER_AGENT'] ?? 'Sin definir';?></p>
	<h1>Datos del servidor web:</h1>
	<p>Dirección IP: <?php echo $_SERVER['SERVER_ADDR'] ?? 'Sin definir';?></p>
	<p>Nombre de dominio: <?php echo $_SERVER['SERVER_NAME'] ?? 'Sin definir';?></p>
	<p>Software: <?php echo $_SERVER['SERVER_SOFTWARE'] ?? 'Sin definir';?></p>
	<p>Protocolo: <?php echo $_SERVER['SERVER_PROTOCOL'] ?? 'Sin definir';?></p>
	<p>Firma del servidor: <?php echo $_SERVER['SERVER_SIGNATURE'] ?? 'Sin definir';?></p>
</body>
</html>
