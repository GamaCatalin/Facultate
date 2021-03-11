class Person:
    def __init__(self,personID,name,phone):
        if personID == None:
            raise ValueError("Client ID must be valid")
        self._id=personID
        self._name=name
        self._phone=phone        
    
    @property
    def id(self):
        return self._id

    @property
    def name(self):
        return self._name

    @property
    def phone(self):
        return self._phone



    @name.setter
    def name(self,value):
        self._name=value

    @phone.setter
    def phone(self,value):
        if len(value)!= 10:
            raise ValueError("Phone is not avalable")
        self._phone=value



class Activity:
    def __init__(self,activityID,personID,date,time,description):
        self._aid=activityID
        self._pid=personID
        self._date=date
        self._time=time
        self._description=description


    @property
    def aid(self):
        return self._aid

    @property
    def pid(self):
        return self._pid

    @property
    def date(self):
        return self._date

    @property
    def time(self):
        return self._time

    @property
    def description(self):
        return self._description

    @date.setter
    def date(self,value):

        self._date=value

    @time.setter
    def time(self,value):

        self._time=value

    @description.setter
    def description(self,value):

        self._description=value

