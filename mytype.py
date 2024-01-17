from property import Prpt, PrptClass


ary = []
p = Prpt("QString",'message')
p.is_bindable = False
p.is_writable = True
p.is_notify = True
ary.append(p)
classMsg = PrptClass("Msg", ary)
        
ary = []
p = Prpt("QString",'firstName')
p.is_bindable = True
p.is_writable = True
p.is_notify = True
ary.append(p)
p = Prpt("QString",'lastName')
p.is_bindable = True
p.is_writable = True
p.is_notify = True
ary.append(p)
p = Prpt("QString",'fullName')
p.is_bindable = True
p.is_writable = False
p.is_notify = True
ary.append(p)
p = Prpt("Msg *",'msg')
p.is_bindable = False
p.is_writable = False
p.is_notify = False
p.is_new_in_contr = True
ary.append(p)
classMyType = PrptClass("MyType", ary)
