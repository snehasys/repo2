from flask import Flask, request #import main Flask class and request object

app = Flask(__name__) #create the Flask app

# plid, tag, playCount, LikesCount, similarPLs

class PlayList(object):
    plId = 1            #plName
    def __init__(self, tag:str ):
      self.id = PlayList.plId
      PlayList.plId += 1    # will allocate new incremented unique id for each new playlist 
      self.name   = tag
      self.artist = 'various artists'
    #   self.date

tagIndex   = {}#{"tagName", "plId"}
playCount  = {}#{"plId", 0}
LikesCount = {}#{"plId", 0}
similarPlaylists = {} #{"plId", []}
allPlaylists = {}


#*******************************************************************
# a.k.a. EXPLORE // http://127.0.0.1:8081/explore?tags=avicii+indie
@app.route('/explore')
def getPLsViaTags():
    global tagIndex
    global ret
    # tags = 'Dilemma+avicii+indie+Butterfly' ### 
    tags = request.args.get('tags')
    # print("$"+tags+"^")
    allTags = tags.split(' ')
    ret={}
    for tag in allTags:
        tag=tag.strip()
        if tagIndex.get(tag, -1) != -1:
            ret[allPlaylists.get(tagIndex[tag]).id ] = tag  # str(tagIndex.get(tag)) # str(allPlaylists.get(tagIndex[tag]).id + '  ')
            for similar in similarPlaylists.get(tagIndex[tag]):
                ret[similar[0]] = str(allPlaylists.get(similar[0]).name)

        # print( str(tagIndex.get(tag, str('$' + tag+' not found'))))
        print(tag)
    # print (tagIndex.items())
    songs = []
    # print(ret.keys())
    for count in sortOnPlayCount():
        if(int(count[0]) in ret.keys()):
            songs.append(ret.get(count[0]))
            print (str(count[0]), ' is present')
    # return str(ret.items())
    return str(songs)

@app.route('/addplaylists')
def addNewPlaylist(tag:str):
    allPlaylists

@app.route('/play')
def play():
    tag = request.args.get('tag')
    if not tag in playCount:
    #     urls_d[url] = 1
        return str("Playlist "+ tag +" not found")
    else:
        playCount[tag] += 1
        return str("<h1>Playing from playlist "+ tag +r" <\h1>")

@app.route('/like')
def likeMusic():
    tag = request.args.get('tag')
    if not tag in LikesCount:
    #     urls_d[url] = 1
        return str("Playlist "+ tag +" not found. nothing to like")
    else:
        LikesCount[tag] += 1
        return str(r"<h1>Liked "+ tag +r" <\h1>")


def sortOnPlayCount():
    return sorted(playCount.items(), key=lambda x: x[1], reverse=True)

def UT_setup():
    testdata = [ "Dilemma", "avicii", "indie", "classical", "best of anouska shankar", "Instrumenntals", "Genie in a Bottle", "Can't Buy Me Love", "Hard to Handle", "Le Freak", "Butterfly", "The Ketchup Song (Aserejé)", "San Francisco (Be Sure to Wear Flowers in Your Hair)", "Uninvited", "zAnother One Bites the Dust", "The Wedding", "Amazing Grace", "Oh, Pretty Woman", "Wannabe", "I Will Survive", "Sweet Mother", "Wind of Change", "Sukiyaki", "Da Da Da", "Rudolph the Red-Nosed Reindeer", "I Want to Hold Your Hand", "Time to Say Goodbye", "Y.M.C.A.", "Do They Know It's Christmas?", "Believe", "Kung Fu Fighting", "Rock Your Baby", "Paper Doll", "The Last Farewell", "Fernando", "Wabash Cannonball", "Diana", "Un-Break My Heart", "My Sweet Lord", "Macarena", "Chirpy Chirpy Cheep Cheep", "I'm a Believer", "Mundian To Bach Ke", "Tennessee Waltz", "Earth Angel","Hound Dog","A Whiter Shade of Pale", "...Baby One More Time", "Petit Papa Noël", "Lady Marmalade", "Simon Says", "Waterloo", "My Blue Heaven", "That Silver-Haired Daddy of Mine", "She Loves You", "Massachusetts", "Karma Chameleon", "Sadeness (Part I)", "Release Me", "Seasons in the Sun", "I'll Be There", "Crimson and Clover", "Delilah", "Great Balls of Fire", "Lambada", "Like a Prayer", "María", "Let's All Chant", "March from the River Kwai", "Can't Get You Out of My Head", "Daydream Believer", "Pass the Dutchie", "I Think I Love You", "Are You Lonesome Tonight?", "Surrender", "Harper Valley PTA", "Il Silenzio", "The Chipmunk Song (Christmas Don't Be Late)", "Ballad of the Green Berets", "I Can Help", "Joy to the World", "Telstar" ]  
    for sampleTag in testdata: # data filler
        pl = PlayList(sampleTag)
        allPlaylists[pl.id] = pl
        tagIndex[sampleTag] = pl.id
        playCount[pl.id]  = 0
        LikesCount[pl.id] = 0
        similarPlaylists[pl.id] = []
    playCount[tagIndex['zAnother One Bites the Dust']] += 1
    playCount[tagIndex['zAnother One Bites the Dust']] += 1
    playCount[tagIndex['avicii']] += 1
    playCount[tagIndex['avicii']] += 1
    playCount[tagIndex['avicii']] += 1
    similarPlaylists.get(tagIndex['avicii']).append([tagIndex['Believe']])
    similarPlaylists.get(tagIndex['avicii']).append([tagIndex['Telstar']])
    similarPlaylists.get(tagIndex['avicii']).append([tagIndex['Surrender']])
    playCount[tagIndex['classical']] += 19

    similarPlaylists.get(tagIndex['classical']).append([tagIndex['best of anouska shankar']])

    playCount[tagIndex['Telstar']] += 7

 
if __name__ == '__main__':
    # print ( getPLsViaTags() ) 
    UT_setup()
    
    app.run(debug=False, port=8081) #run app in debug mode on port 5000
