const express = require ('esxpress')
const app = express()
const port = 80

//const conec = requir('conec/conec.js') codulo futuro de conexão

app.use(express.static('public'))