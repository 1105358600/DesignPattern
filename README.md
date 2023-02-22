## 一、系统的主要目标与功能

　 　&emsp;  在本次设计中，考虑到目前疫情反复不断，为了方便群众，超市都推出在线购物并有配送员送货，于是我设计了一个超市在线网上购物送货的系统，这个系统的主要目标是帮助人们在家里购买自己需要的套餐，充值账户，同时该系统能查看自己的历史金额变动记录，也能够撤销前一次操作，这样能够帮助疫情期间的人们快速购物，也能够减少疫情期间出门购物的可能带来的危害。本超市目前功能如下：

```
1. 查看超市套餐 
2. 购买超市套餐 
3. 给账户充值 
4. 查看历史余额记录 
5. 撤回上次操作  
6. 系统自动提示配送员
7. 退出本超市在线购物系
```

系统运行比较简单，且每一步完成后都会有提示信息，按照提示信息一步一步运行即可。

## 二 、系统中使用的设计模式（UML类图、详细描述场景、解决的问题、模式的效果及意义）

![在这里插入图片描述](https://img-blog.csdnimg.cn/29e716d5d65f48d99204337830559ccc.png)

## **•1.状态模式**：

　　&emsp;对有状态的对象，把复杂的“判断逻辑”提取到不同的状态对象中，允许状态对象在其内部状态发生改变时改变其行为。在一个对象内在状态改变时也改变了其行为，这个对象看起来像改变了其类，因此选择使用状态模式。
•![在这里插入图片描述](https://img-blog.csdnimg.cn/26ccc7b527f34157b74efdbf82c669bf.png)

　　&emsp;**•设计思路**：在本系统中，状态模式在购物时提供用户信息和余额的信息，分别为正常状态GreenState，欠款状态RedState与会员VIP状态。在进入程序时便初始化账户Account，通过这个账户记录余额balance信息，同时考虑到余额不足时不能购物，考虑到特殊情况，设计余额不足购买时允许赊欠，但当前余额小于0时不能购物，这样是考虑到实际，余额小于0时是不能购买的；此外若充值后余额超过1000元，则当前状态变为VIP模式，之后购买商品可以有8折优惠。

　　&emsp;**程序设计**：Account中有属性state来聚合AccountState记录当前Account的状态，且有RedState，GreenState，VIP三个子状态继承AccountState，AccountState中有balance余额属性，在每个子状态里面有stateCheck()函数，可以在调用该函数后判断balance的数值，来改变当前Account所处的状态，并在改变状态后改变消费的行为。Accout有函数deposit和withdraw，分别是存款和取款来对balance进行操作，并会根据属性state的不同有不同的行为。

![在这里插入图片描述](https://img-blog.csdnimg.cn/47bb147acd374c86b3379b22faaa7771.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/4767464811d04431832e9446cf9e97f3.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/c1cb76901ed74fc8b414b58ab9178f6b.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/076a5b76f65747e0adf2116e18e7fa72.png)

　　&emsp;Account中有属性msStrategy，这是与策略模式结合的属性，在代码中设计的为若状态为GreenState或RedState，即初试化为MessageStrategy2直接在窗口输出，若为VIP状态，则初试化为MessageStrategy1，产生MessageBox弹窗通知。
![在这里插入图片描述](https://img-blog.csdnimg.cn/d9bf52d8586a4a3ab5313936ab14273d.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/5614c4e5f8c64d419ed0105546c0077e.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/a09519a9b8ef4fd0a51aaee7c9b37494.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/f8a55f4b0a7e4fa29d202a895d789934.png)





## **•2.建造者模式**

　　&emsp;建筑者模式封装一个产品的构造过程, 并允许按步骤构造. 将一个复杂对象的构建与它的表示分离, 使得同样的构建过程可以创建不同的表示。
•![在这里插入图片描述](https://img-blog.csdnimg.cn/94beb1b41bca43669c0041bb97a01e38.png)

　　&emsp;**设计思路**：在本系统中建造者模式可用于构建不同的套餐1，套餐2，套餐3，由超市Supermarket作为指挥者，将套餐的内部表象与生成过程分割开来，从而可以使一个建造过程生成具有不同的内部表象的产品对象Product，并且使客户便于查看各个套餐的内容与价格便于购买。

　　&emsp;**程序设计**：首先Supermarket是系统中建造者模式的Director指导者，拥有Construct()函数，且拥有Builder类的bld属性，使用Construct（）即可调佣bld中的BuildPartA，B，C函数，来构建出Product产品类，从而返回Product完成建造，将Product的复杂构造在ConcreteBuilder内实现，而Supermarket只需要设置不同的bld属性和调用Construct（）函数，即可创建不同的产品，实现产品构建的封装。

![在这里插入图片描述](https://img-blog.csdnimg.cn/b3f91294bfa547348d77f97e5ca6d8a3.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/d41a8aabb9b14d50a2905f208938b4e4.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/1570761ef9b04a728ff8bff0335e279a.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/0f56134ea6184bb68caccb6d60d0581f.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/01b08cd82f314f2cab539df0df2c4d5e.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/ebd822a475e0444b9725b66f5f4a976a.png)



## **•3.观察者模式**

　　&emsp;观察者模式建立一种对象与对象之间的依赖关系，一个对象发生改变时将自动通知其他对象，其他对象将相应作出反应。在此，发生改变的对象称为观察目标，而被通知的对象称为观察者，一个观察目标可以对应多个观察者，而且这些观察者之间没有相互联系，可以根据需要增加和删除观察者，使得系统更易于扩展。
![在这里插入图片描述](https://img-blog.csdnimg.cn/68453b4ddf944f9cb77bd6c6af4a1716.png)

　　&emsp;**设计思路**：在本系统中，观察者模式的观察目标为商家系统Supermarket，具体观察者为配送员DeliveryObserver，多个配送员DeliveryObserver观察对应的商家系统Supermarket，当有客户在商家购买套餐时，商家系统会发出通知提醒观察了自己的配送员。

　　&emsp;**程序设计**：在Supermarket中有Attach()和Detach()两个函数与list<DeliveryObserver*>accs即 DeliveryObserver的一个列表，Attach()来增加配送员Observer为观察者，Detach()删除观察者Observer，然后在消费者进行购物后，通过调用notify（）函数来进行通知，且Observer中具体的notify（）函数与策略模式相结合，对于list中的单数采用MessageStrategy1通知，list采用MessageStrategy2来通知。
![在这里插入图片描述](https://img-blog.csdnimg.cn/f9a8ff7ec1c6479bac3c6e234303f760.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/4bb27ae8ffa04ca8b886d4d26e4016f7.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/0ae1595ef22f42f793c7e005c1b9d2dc.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/21b333daa46e4dbe83b4561b37251adc.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/1ec75e41fd7a41569f9929d306e70107.png)





## **•4.单例模式**

　　&emsp;单例类只有一个实例对象，且该单例对象必须由单例类自行创建，单例类对外提供一个访问该单例的全局访问点。
•![在这里插入图片描述](https://img-blog.csdnimg.cn/513081c9bb1547d3a30cc69ac1c9de5d.png)

　　&emsp;**设计思路**：在本系统中，单例类为商家类，只允许创建一个商家类，且该商家类是建造者模式的指挥者，指挥套餐的建立。





　　&emsp;**程序设计**：在Supermarket里面，有私有静态的Supermarket类属性_instance，然后将构造函数定义为保护函数防止外界调用，在调用构造函数时判断_instance是否为空，若为空则可初始化，否则返回_instance。
![在这里插入图片描述](https://img-blog.csdnimg.cn/7d2d5f1b06af45a194a8f1ac53adef07.png)

## **•5.策略模式**

　　&emsp;该模式定义了一系列算法，并将每个算法封装起来，使它们可以相互替换，且算法的变化不会影响使用算法的客户。策略模式的主要目的是将算法的定义与使用分开，将算法的定义放在专门的策略类中，每一个策略类封装了一种实现算法，在出现新的算法时，只需要增加一个新的实现了抽象策略类的具体策略类即可。
![在这里插入图片描述](https://img-blog.csdnimg.cn/527f6cbe963b46f18d3cc2c57e6ff0d0.png)



　　&emsp;**设计思路**：本系统中，策略模式在观察者模式的基础上使用，在观察者模式通知Observer时，通知方式可选择不同的策略，如短信通知或软件信息通知等，在本系统中选择弹窗通知MessageStrategy1与直接输出通知MessageStrategy2来模拟这两种不同的通知方式。

　　&emsp;此外，策略模式与状态模式也有在一起联合使用，若Account目前状态为GreenState或RedState，即初试化为MessageStrategy2直接在命令行窗口输出，若为VIP状态，则初试化为MessageStrategy1，产生MessageBox弹窗通知。
![在这里插入图片描述](https://img-blog.csdnimg.cn/28ba57e3df484487802f18c70e2daa7d.png)

　　&emsp;**程序设计**：MessageStrategy有两个子类，分别为MessageStrategy1与MessageStrategy2，MessageStrategy1即采用MessageBox进行弹窗输出，而MessageStrategy2即为cout直接输出，使用时可具体不同的策略类来实现不同的通知方式

![在这里插入图片描述](https://img-blog.csdnimg.cn/51a47eba58af413c8b58b36b9b428ba5.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/ad34e75290bd4868bbc68dc3a6f238dc.png)

## **•6.备忘录模式**

　　&emsp;在不破坏封装性的前提下捕获一个对象的内部状态，并在对象之外保存这个状态。这样以后就可以将对象恢复到原先保存的状态。

![在这里插入图片描述](https://img-blog.csdnimg.cn/8e18d18db0d744a180e21fcf5cc097e5.png)

　　&emsp;**设计思路**：在本系统中，备忘录模式记录在系统中的余额变动，并可查看所有的历史变动记录，并可以撤销上一次余额变动的操作，在现实中大部分购物应用都可以查看历史记录与撤销，因此利用备忘录模式实现该操作，便于观察余额变化。

　　&emsp;**程序设计**：首先通过UserInfoDTO来在主函数中将每次余额改变时的balance即state记入Memento，然后利用Caretaker中的mementoList来记录每次余额改变后的Memento值。在查看历史记录时，即调用UserInfoDTO的getStateFromMemento()函数来遍历mementoList所有记录的历史余额；在想要进行撤销操作时，即首先调用user.getStateFromMemento（）获取最近一次操作后的余额值，之后调用p->setbalance(user.getState())将余额记录到Account账户中，且对于第一次操作与第0次操作有不同的撤销行为。
![在这里插入图片描述](https://img-blog.csdnimg.cn/48e55a9cdaa544289983980de04c5002.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/9039bf56cf2744739f2bf992cc152bb9.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/f9b1baa6ea3040f897926adb72b90ce0.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/bccef95d0a2841c089aa32e9f61f34f5.png)

## 三、系统运行截图

　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/d4eba3ae8fca4f298445862e4882315c.png)

　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/c889e815a1dd4c66a079f7958c216bff.png)

　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/5496faa0836147c38000b08043628143.png)

　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/b7517714ff2c4e2a9f148218038ac69a.png)
　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/b38a9f2f2c4c418895c53553a3df016f.png)
　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/cfcc808f89b54ff28dd09d6a0af33c28.png)
　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/037e3bb584024e37b74506c71b70e488.png)
　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/6f25eed893244f32a40acc48afed3125.png)
　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/5c26d58236b94c548db57532dfe2e4dc.png)
　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/7e73595441a64362a10661e0fee5e3ca.png)

   　　　&emsp;　　&emsp;![在这里插入图片描述](https://img-blog.csdnimg.cn/30d1a910fe4c4d13b779cafbcf78f63a.png)







## 四、设计模式总结

  　　&emsp; 本次实践作业我使用了一些比较常见的设计模式，包括状态模式，单例模式，建造者模式，观察者模式，策略模式，备忘录模式。我个人认为在设计模式的使用有两个亮点。
  　&ensp;第一个亮点就是策略模式与观察者模式与状态模式联合使用，而不是将策略模式进行单一的使用。这个想法是我在进行观察者模式设计时，发现观察者模式的通知功能可以有不同的策略实现后做出的模式设计。我将策略模式与观察者模式与状态模式联合使用，对于不同的观察者，不同的状态时会有不同的行为，因此我将策略模式融合到这两种模式中，这也是对于设计模式的一种深入使用，而不仅仅是生硬的套用。在本次实践中，。
　&ensp; 第二个亮点是备忘录模式的使用，我个人认为备忘录模式的理解和代码设计都有一定的难度，在实践过程中也确实遇到了一些困难如Caretaker和Memento的区别，以及如何存和取历史数据，但经过认真学习进行了解决。
　&ensp; 通过使用这些设计模式，代码对修改有了封闭性，在客户端没有具体实现，难以修改，而在进行扩展时更加容易，如对于策略模式，如果想要添加一个新的策略实现不同的通知方式，只需要增加一个策略实现的子类MessageStrategy3即可实现策略添加。

## 五、个人的模式学习心得

　&emsp;在本次面向对象与系统建模的课程学习中，我个人认为收获良多，与本科学习过的设计模式相比学到了更多与更加深入，首先是因为研一与本科学习时相比自己做过的项目与见过的代码更多，更加理解了为什么要运用设计模式来进行代码封装与复用，如何使用设计模式来更好的扩展代码，为什么设计代码时要满足开闭原则等多项原则。（而不像是本科学习时觉得进行这些设计模式的使用没有用处，反而让人看不懂代码具体逻辑）。
&emsp;此外，也正是提前了解到了设计模式的重要性，我学习的兴趣也更加浓厚，因此我除了在上课时的学习，还购买了《大话设计模式》进行课外学习，同时参加了软件设计师的考试，于是我对设计模式的复用性有了更深入的了解，对于重要的模式如观察者模式、状态模式、工厂模式，适配器模式等理论方面有了更加深入的理解，对于每种设计模式的UML类图也更加理解，对于该在哪种应用场景来使用某种设计模式、如何用代码实现这些模式也更加明确，对一些不太常见的模式如原型模式，访问者模式也了解更多，更加理解了设计模式对于修改封闭，扩展开放的好处，对于迪米特法则、单一职责原则等更加理解。

## 六、意见和建议

　&emsp;个人认为对于设计模式的学习不能追求通过上课来速成，要在自己进行代码编写的过程中以及后续代码修改过程中才能深入理解设计模式的重要性。
&emsp;因此对于学习过程中建议可以不用课本，直接用能够运行的使用了2-3个设计模式的简单项目，并编写2个不同的代码，一个没有使用设计模式的代码，一个使用了设计模式代码，首先演示让同学们了解代码的作用，然后平时作业可以让同学们分别对两种代码进行扩展，如对于状态模式，可以让学生对两种代码都加一种状态，这样可能比对着书本更容易理解设计模式的作用，而在期末作业上也可以要求同学们对于上课时的简单项目进行扩展，如多加几个设计模式。

## 七、main函数与抽象类代码

　&emsp;Main函数：可以看到在Main函数与抽象类中没有看到具体的实现代码，仅仅只有函数的调用，因此基本满足开闭原则，扩展性良好，想要扩展时仅仅只需要增加子类。
![在这里插入图片描述](https://img-blog.csdnimg.cn/d34b4e06cb0446d5857abc91aac6d1f1.png)









.



