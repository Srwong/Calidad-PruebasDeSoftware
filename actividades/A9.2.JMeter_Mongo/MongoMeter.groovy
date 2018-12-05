import com.mongodb.*;

MongoClient cli = new MongoClient("localhost", 27017); //cliente para conexion

DB mydb = cli.getDB("test"); //obtener base de datos

DBCollection nombres = mydb.getCollection("nombres"); //obtener la coleccion

//BasicDBList Arreglos
//BasicDBObject Doc Simple
//DBObject read docs

//creamos los objetos
BasicDBObject dbbo = new BasicDBObject();
dbbo.append("nombre", "Julio");
//dbbo.append("nombre", "rodrigo");

//ahora necesitamos añadirlos con un writter
WriteResult writer = nombres.insert(dbbo, WriteConcern.ACKNOWLEDGED);

//para saber si se escribio o no
if(writer.wasAcknowledged())
    OUT.println("Se escribio el objecto en la BD");
else
    OUT.println("No se escribio el objeto en la BD");

SampleResult.setResponseData(writer.toString().getBytes());

//insertar arreglo de documentos
dbbo = new BasicDBObject();
dbbo.append("nombre", "Rosita");

//creamos la lista
BasicDBList dbbl = new BasicDBList();
dbbl.add("56876351365");
dbbl.add("36856178137");
dbbl.add("92143253311");

dbbo.append("telefonos", dbbl);
writer = nombres.insert(dbbo, WriteConcern.ACKNOWLEDGED);
SampleResult.setResponseData(writer.toString().getBytes());

BasicDBObject busqueda = new BasicDBObject("nombre", "Rosita");
DBCursor dbo = nombres.find(busqueda);

StringBuilder s = new StringBuilder();

while(dbo.hasNext())
{
    DBObject res = dbo.next();
    //println(res.toString());
    s.append(res.toString());
}
/*
En Jmeter tenemos 3 tipos de variables:

variables vars
propiedades props
System

variables es individual y las otras dos son compartidas
*/


//asi se usa la variable declarada en el plan de pruebas en jmeter
vars.put("resultado",s.toString());
