const express = require('express')
const router = express.Router()

const path = require('path')

const basePath = path.join(__dirname, '../templates')

router.get('/ligar', (req, res) => {
    res.sendFile(`${basePath}/ligar.html`)
})

module.exports = router
