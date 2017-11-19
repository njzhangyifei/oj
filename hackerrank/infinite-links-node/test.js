var request = require('request');
const cheerio = require('cheerio')

var base_url = "https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/infinite/"
var start_url = "qds.html"
var visited = [start_url]
var password = []
function geturl(url){
    request(url, function (error, resp, body) {
        var $ = cheerio.load(body);
        var str = $('font').text().replace('Secret Phrase: ', '');
        if (str != '') { 
            console.log(str);
        }
        $('a').each(function(i, element){
            // console.log($(this).attr('href'))
            var new_url = $(this).attr('href');
            if (visited.indexOf(new_url) > -1){
                // console.log('done');
            } else {
                // console.log(new_url);
                visited.push(new_url);
                // console.log(visited.length)
                geturl(base_url + new_url)
            }
        })
    })
}

geturl(base_url+start_url);
