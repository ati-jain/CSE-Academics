// const mysql = require('mysql');
// const fs = require('fs');
import mysql from "mysql2";
import fs from "fs";

var config = {
  host: "dbms-hostpital.mysql.database.azure.com",
  user: "atishay",
  password: "pass@123",
  database: "hospital",
  port: 3306,
  ssl: { cs: fs.readFileSync("./files/BaltimoreCyberTrustRoot.crt.pem") },
};

const conn = new mysql.createConnection(config);

conn.connect(function (err) {
  if (err) {
    console.log("!!! Cannot connect !!! Error:");
    throw err;
  } else {
    console.log("Connection established.");
    queryDatabase();
  }
});

function queryDatabase() {
  
}
