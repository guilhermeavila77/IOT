const express = require('express')
const app = express()
const port = 3000

const onOff = require('./onOff')
//const conec = requir('conec/conec.js') Modulo futuro de conexão

const path = require('path')

const basePath = path.join(__dirname, 'templates')

app.use(express.static('public'))

app.use(onOff)

app.get("/", (req, res) => {
    res.sendFile(`${basePath}/index.html`);
});

app.listen(port, () => {
    console.log(`localhost:${port}`);
});
