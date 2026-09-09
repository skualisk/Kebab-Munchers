/*Supermarket management system, by Aarron Dcruz 2661123, Anshuman Singh 2661126, 
  Yankit Gupta 2661144 and Uneeth Singh 2661183*/
#import <stdio.h>
#import <string.h>
struct Cart //Bro struct is like a reusable variable thing
{
  char pname[50];
  float price;
  float quan;
  
}
struct Product{
    int ASid;
    char ASname[50];
    float ASprice;
    int ASquantity;
}
void AddCart();
void ASsearchProduct();
void ASapplyDiscount();

void RemoveCart();

void ASaddProduct();
int main()
{

}

void AddCart()
{
  struct Cart Ad;
  printf("Enter Product Name: ");
  gets(Ad.pname);
  printf("Enter Price of Product");  // Am thinking we read this from our inventory.csv file but little complex
  scanf("%f", &Ad.price);
  printf("Enter Quantity of Product");
  scanf("%f", &Ad.quan)

  FILE *fad = fopen("Cart.csv", "a");
  if (fad == NULL)
  {
    printf("File not Found");
    exit(0);
  }
  fprintf(fad, %s, %.4f, %.2f, Ad.pname, Ad.price, Ad.quan);   // Another thinng, do we add tax per item or tax the whole thing
  printf("-------------- ITEM ADDED SUCCESSFULLY --------------");

  f.close(fad);
}

void RemoveCart()
{
  char IName[50];
  printf("Enter Item Name to be removed:\t");
  gets(IName);
  File *fde = fopen("Cart.csv", r);
  File *ftemp = fopen("Temp.csv", a);
  char line[256];
  int found;
  while (fgets(line, sizeof[line], fde) != NULL)
  {
    line(strcspn(line, "\n")) = 0;
    char *name = strok(line, ",");
    char *price = strok(NULL, ",");
    char *quan = strok(NULL, ",");
    if (strcmp(IName, *name) == 0)
    {
      found = 1;
      continue;
    }
    fprintf(ftemp, %s, %s, %s, *name, *price, *quan);
  }
  fclose(fde);
  fclose(ftemp);
  if (found == 1)
  {
    printf("Item Not Found");
  }
  else
    printf("----------------- ITEM DELETED FROM CART -----------------");
  remove ("Cart.csv");
  rename ("Temp.csv", "Cart.csv");
}
void ASaddProduct(){
	struct Product ASproduct;
	FILE*ASfile;
	
	ASfile=fopen("products.csv",a);//opening file in apppppeeeennnddd
	if(ASfile==NULL){
		printf("ERROR!!\n");
		return;
	}
	//taking product
	printf("ENTER PRODUCT ID:");
	scanf("%d",&ASproduct.ASid);
	printf("ENTER PRODUCT NAME:");
	scanf("%d",&ASproduct.ASname);
	printf("ENTER PRODUCT PRICE:");
	scanf("%d",&ASproduct.ASprice);
	printf("ENTER PRODUCT QUANTITY:");
	scanf("%d",&ASproduct.ASquantity);
	fprintf(ASfile,"%d %s %.2f %d\n",ASproduct.ASid,ASproduct.ASname,ASproduct.ASprice,ASproduct.ASquantity);
	
	fclose(ASfile);
	printf("\n PRODUCT ADDED !\n");
	
}   
void ASdisplayProducts() {
    struct Product ASproduct;
    FILE *ASfile;

    // Open file in read mode
    ASfile = fopen("products.csv", "r");
    if (ASfile == NULL) {
        printf(" Error!\n");
        return;
    }

    printf("\n--- Product List ---\n");
    printf("ID\tName\tPrice\tQuantity\n");
    printf("---------------------------------\n");

    // Read each product line by line
    while (fscanf(ASfile, "%d %s %f %d",
                  &ASproduct.ASid,
                  ASproduct.ASname,
                  &ASproduct.ASprice,
                  &ASproduct.ASquantity) != EOF) {
        printf("%d\t%s\t%.2f\t%d\n",
               ASproduct.ASid,
               ASproduct.ASname,
               ASproduct.ASprice,
               ASproduct.ASquantity);
    }

    fclose(ASfile);
}

void ASsearchProduct() {
    struct Product ASproduct;
    FILE *ASfile;
    int ASsearchId;
    char ASsearchName[50];
    int ASfound = 0;
    int ASchoice;

    ASfile = fopen("products.csv", "r");
    if (ASfile == NULL) {
        printf("? Error opening file!\n");
        return;
    }

    printf("Search by:\n1. Product ID\n2. Product Name\nEnter choice: ");
    scanf("%d", &ASchoice);

    if (ASchoice == 1) {
        printf("Enter Product ID: ");
        scanf("%d", &ASsearchId);

        while (fscanf(ASfile, "%d,%49[^,],%f,%d",
                      &ASproduct.ASid,
                      ASproduct.ASname,
                      &ASproduct.ASprice,
                      &ASproduct.ASquantity) != EOF) {
            if (ASproduct.ASid == ASsearchId) {
                printf("\n? Product Found!\n");
                printf("ID: %d | Name: %s | Price: %.2f | Quantity: %d\n",
                       ASproduct.ASid, ASproduct.ASname,
                       ASproduct.ASprice, ASproduct.ASquantity);
                ASfound = 1;
                break;
            }
        }
    } else if (ASchoice == 2) {
        printf("Enter Product Name: ");
        scanf("%s", ASsearchName);

        while (fscanf(ASfile, "%d,%49[^,],%f,%d",
                      &ASproduct.ASid,
                      ASproduct.ASname,
                      &ASproduct.ASprice,
                      &ASproduct.ASquantity) != EOF) {
            if (strcmp(ASproduct.ASname, ASsearchName) == 0) {
                printf("\n? Product Found!\n");
                printf("ID: %d | Name: %s | Price: %.2f | Quantity: %d\n",
                       ASproduct.ASid, ASproduct.ASname,
                       ASproduct.ASprice, ASproduct.ASquantity);
                ASfound = 1;
                break;
            }
        }
    }

    if (!ASfound) {
        printf("\n? Product Not Found!\n");
    }

    fclose(ASfile);
}



float ASapplyDiscount(float AStotal) {
    float ASdiscount = 0.0;

    if (AStotal > 1000) {
        ASdiscount = AStotal * 0.10;   // 10% discount
    } else if (AStotal > 500) {
        ASdiscount = AStotal * 0.05;   // 5% discount
    }

    float ASfinalAmount = AStotal - ASdiscount;

    printf("\n--- Discount Applied ---\n");
    printf("Original Total: %.2f\n", AStotal);
    printf("Discount: %.2f\n", ASdiscount);
    printf("Final Amount: %.2f\n", ASfinalAmount);

    return ASfinalAmount;
}


