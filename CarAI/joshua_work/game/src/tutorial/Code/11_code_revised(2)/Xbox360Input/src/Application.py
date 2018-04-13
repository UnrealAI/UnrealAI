from direct.showbase.ShowBase import ShowBase
from direct.actor.Actor import Actor
from panda3d.core import *
from FollowCam import FollowCam
from KeyboardMouseHandler import KeyboardMouseHandler
from XboxControllerHandler import XboxControllerHandler

class Application(ShowBase):
    def __init__(self):
        ShowBase.__init__(self)
        self.world = loader.loadModel("environment")
        self.world.reparentTo(render)
        self.world.setScale(0.5)
        self.world.setPos(-8, 80, 0)

        self.panda = Actor("panda", {"walk": "panda-walk"})
        self.panda.reparentTo(render)

        self.followCam = FollowCam(self.cam, self.panda)

        self.keyInput = KeyboardMouseHandler()
        self.xboxInput = XboxControllerHandler()

        self.accept("walk-start", self.beginWalk)
        self.accept("walk-stop", self.endWalk)
        self.accept("reverse-start", self.beginReverse)
        self.accept("reverse-stop", self.endReverse)
        self.accept("walk", self.walk)
        self.accept("reverse", self.reverse)        
        self.accept("turn", self.turn)
        
    def beginWalk(self):
        self.panda.setPlayRate(1.0, "walk")
        self.panda.loop("walk")

    def endWalk(self):
        self.panda.stop()

    def beginReverse(self):
        self.panda.setPlayRate(-1.0, "walk")
        self.panda.loop("walk")

    def endReverse(self):
        self.panda.stop()

    def walk(self, rate):
        self.panda.setY(self.panda, rate)

    def reverse(self, rate):
        self.panda.setY(self.panda, rate)        

    def turn(self, rate):
        self.panda.setH(self.panda, rate)
